#include <linux/module.h>
#include <linux/err.h>
#include <linux/platform_device.h>
#include <linux/power_supply.h>
#include <linux/types.h>
#include <linux/pci.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/acpi.h>
#include <linux/miscdevice.h>
#include <linux/kernel.h>

struct goldfish_segment_data {
	void __iomem *reg_base;
};

#define GOLDFISH_SEGMENT_READ(data, addr) \
	(readl(data->reg_base + addr))
#define GOLDFISH_SEGMENT_WRITE(data, addr, x) \
	(writel(x, data->reg_base + addr))

enum  {
	SEGMENT0    = 0x000,
	SEGMENT1    = 0x004,
	SEGMENT2    = 0x008,
	SEGMENT3    = 0x00C,
	SEGMENT4    = 0x010,
	SEGMENT5    = 0x014,
	SEGMENT6    = 0x018,
};

#define CMD1 0x04
#define CMD2 0x05
#define CMD3 0x06


struct goldfish_segment_data *segment_data;

static int segment_open(struct inode *inode, struct file *file){
	printk(KERN_INFO "segment file is open\n");
	return 0;
}

static int segment_release(struct inode *inode, struct file *file){
	printk(KERN_INFO "segment file is closed\n");
	return 0;
}

static ssize_t segment_read(struct file *file, char __user *buf, size_t size, loff_t *loff){
	char kbuf[8];

	int i=0;
	while(i<8){
		kbuf[i] = GOLDFISH_SEGMENT_READ(segment_data, i*4);
		i++;
	}
	copy_to_user(buf, kbuf, sizeof(kbuf));

	return sizeof(kbuf);
}

static ssize_t segment_write(struct file *file, char __user *buf, size_t size, loff_t *loff){
	char kbuf[8];

	copy_from_user(kbuf, buf, sizeof(kbuf));

	int i = 0;
	while(i<8) GOLDFISH_SEGMENT_WRITE(segment_data, i*4, kbuf[i++]);

	return sizeof(kbuf);
}

static int segment_mmap(struct file *file, struct vm_area_struct *vma){
	if(remap_pfn_range(vma, vma->vm_start, vma->vm_pgoff, vma->vm_end - vma->vm_start, vma->vm_page_prot)){
		printk(KERN_INFO "segment MMAP fa\n");
		return -EAGAIN;
	}
	return 0;
}

static long segment_ioctl(struct file *file, unsigned int cmd, unsigned long para){
	switch(cmd){/*
		case CMD1:
			break;
		case CMD2:
			break;*/
		case CMD3:
			printk("week4_test_segment_%d\n", (int)para+1);
			break;
		default:
			break;
	};
	return 0;
}

static const struct file_operations segment_fops = {
	.owner = THIS_MODULE,
	.read = segment_read,
	.write = segment_write,
	.unlocked_ioctl = segment_ioctl,
	.compat_ioctl = segment_ioctl,
	.open = segment_open,
	.release = segment_release,
	.mmap = segment_mmap,

};

static struct miscdevice segment_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "segment",
	.fops = &segment_fops
};



asmlinkage long sys_segment(int x){

	int a = x;
	
	int c[7] = {0x018, 0x014, 0x010, 0x00C, 0x008, 0x004, 0x000};
	int b[10]= {0x77, 0x24, 0x5d, 0x6d, 0x2e, 0x6b, 0x7a, 0x27, 0x7F, 0x2f};
	
	/*if(a > 9999999) a = 9999999;
	if(a < 0) a = 0;

	int i=0;

	while(a){
		GOLDFISH_SEGMENT_WRITE(segment_data, c[i], b[a%10]);
		a = a/10;
		i++;
	}
	while(i<7){	
		GOLDFISH_SEGMENT_WRITE(segment_data, c[i], 0x77);
		i++;
	}*/
	
	if(x == 0){
		int i = 0;
		while(i<7){	
			GOLDFISH_SEGMENT_WRITE(segment_data, c[i], 0);
			i++;
		}
		return 0;
	}
	
	
	int k = a/100;
	
	int l = a - k*100;
	
	int i = 0;
	
	if(k>9){
		GOLDFISH_SEGMENT_WRITE(segment_data, c[6], b[k/10]);
		GOLDFISH_SEGMENT_WRITE(segment_data, c[5], b[k%10]);
		if(l>9){
			GOLDFISH_SEGMENT_WRITE(segment_data, c[1], b[l/10]);
			GOLDFISH_SEGMENT_WRITE(segment_data, c[0], b[l%10]);	
			i = 2;
			while(i<5) GOLDFISH_SEGMENT_WRITE(segment_data, c[i++], 0);
		}
		else{
			GOLDFISH_SEGMENT_WRITE(segment_data, c[0], b[l]);
			i = 2;
			while(i<6) GOLDFISH_SEGMENT_WRITE(segment_data, c[i++], 0);	
		}
	}
	else{
		GOLDFISH_SEGMENT_WRITE(segment_data, c[6], b[k]);
		if(l>9){
			GOLDFISH_SEGMENT_WRITE(segment_data, c[1], b[l/10]);
			GOLDFISH_SEGMENT_WRITE(segment_data, c[0], b[l%10]);	
			i = 1;
			while(i<5) GOLDFISH_SEGMENT_WRITE(segment_data, c[i++], 0);
		}
		else{
			GOLDFISH_SEGMENT_WRITE(segment_data, c[0], b[l]);
			i = 1;
			while(i<6) GOLDFISH_SEGMENT_WRITE(segment_data, c[i++], 0);	
		}
	}
	

	return 0;
}

static int goldfish_segment_probe(struct platform_device *pdev)
{
	int ret;
	struct resource *r;

	printk(KERN_ERR "segment probe started\n");
	segment_data = devm_kzalloc(&pdev->dev, sizeof(segment_data), GFP_KERNEL);
	if (segment_data == NULL)
		return -ENOMEM;

	r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (r == NULL) {
		dev_err(&pdev->dev, "platform_get_resource failed\n");
		return -ENODEV;
	}

	if(request_mem_region(r->start, resource_size(r), "7segment")==NULL){
		printk(KERN_INFO "register 7segment fail\n");
		return -EBUSY;
	}

	misc_register(&segment_dev);

	segment_data->reg_base = devm_ioremap(&pdev->dev, r->start, resource_size(r));
	if (segment_data->reg_base == NULL) {
		dev_err(&pdev->dev, "unable to remap MMIO\n");
		return -ENOMEM;
	}

	printk(KERN_ERR "segment probe finished\n");

	GOLDFISH_SEGMENT_WRITE(segment_data, SEGMENT0, 0x24);
	GOLDFISH_SEGMENT_WRITE(segment_data, SEGMENT1, 0x5d);
	GOLDFISH_SEGMENT_WRITE(segment_data, SEGMENT2, 0x6d);
	GOLDFISH_SEGMENT_WRITE(segment_data, SEGMENT3, 0x2e);
	GOLDFISH_SEGMENT_WRITE(segment_data, SEGMENT4, 0x6b);
	GOLDFISH_SEGMENT_WRITE(segment_data, SEGMENT5, 0x7a);
	GOLDFISH_SEGMENT_WRITE(segment_data, SEGMENT6, 0x27);

	return 0;
}

static int goldfish_segment_remove(struct platform_device *pdev)
{
	return 0;
}


static const struct of_device_id goldfish_segment_of_match[] = {
	{ .compatible = "generic,goldfish_segment", },
	{},
};
MODULE_DEVICE_TABLE(of, goldfish_segment_of_match);

static const struct acpi_device_id goldfish_segment_acpi_match[] = {
	{ "GFSH0001", 0 },
	{ },
};
MODULE_DEVICE_TABLE(acpi, goldfish_segment_acpi_match);


static struct platform_driver goldfish_segment_device = {
	.probe		= goldfish_segment_probe,
	.remove		= goldfish_segment_remove,
	.driver = {
		.name = "goldfish_segment",
		.of_match_table = goldfish_segment_of_match,
		.acpi_match_table = ACPI_PTR(goldfish_segment_acpi_match),
	}
};
module_platform_driver(goldfish_segment_device);


MODULE_AUTHOR("Jinkyu Jeong wowzerjk@gmail.com");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("7 segment driver for the Goldfish emulator");
