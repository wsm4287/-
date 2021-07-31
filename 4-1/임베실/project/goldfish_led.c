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

struct goldfish_led_data {
	void __iomem *reg_base;
};

#define GOLDFISH_LED_READ(data, addr) \
	(readl(data->reg_base + addr))
#define GOLDFISH_LED_WRITE(data, addr, x) \
	(writel(x, data->reg_base + addr))

enum  {
	LED0    = 0x000,
	LED1    = 0x004,
	LED2    = 0x008,
	LED3    = 0x00C,
	LED4    = 0x010,
	LED5    = 0x014,
	LED6    = 0x018,
};

#define CMD1 0x04
#define CMD2 0x05
#define CMD3 0x06
#define CMD4 0x07
#define CMD5 0x08
#define CMD6 0x09
#define CMD7 0x0A



struct goldfish_led_data *data;

static int led_open(struct inode *inode, struct file *file){
	printk(KERN_INFO "led file is open\n");
	return 0;
}

static int led_release(struct inode *inode, struct file *file){
	printk(KERN_INFO "led file is closed\n");
	return 0;
}

static ssize_t led_read(struct file *file, char __user *buf, size_t size, loff_t *loff){
	char kbuf[8];
	int i=0;
	while(i<8){
		kbuf[i] = GOLDFISH_LED_READ(data, i*4);
		i++;
	}

	copy_to_user(buf, kbuf, sizeof(kbuf));

	return sizeof(kbuf);
}

static ssize_t led_write(struct file *file, char __user *buf, size_t size, loff_t *loff){
	char kbuf[8];

	copy_from_user(kbuf, buf, sizeof(kbuf));
	int i=0;
	while(i<8){
		GOLDFISH_LED_WRITE(data, i*4, kbuf[i++]);
	}

	return sizeof(kbuf);
}

static int led_mmap(struct file *file, struct vm_area_struct *vma){
	if(remap_pfn_range(vma, vma->vm_start, vma->vm_pgoff, vma->vm_end - vma->vm_start, vma->vm_page_prot)){
		printk(KERN_INFO "led MMAP fa\n");
		return -EAGAIN;
	}
	return 0;
}

static long led_ioctl(struct file *file, unsigned int cmd, unsigned long para){
	printk("!@#!$!#$!$!\n");
	switch(cmd){
		case CMD1:
			GOLDFISH_LED_WRITE(data, (int)para*4,0x1);
			break;
		case CMD2:
			printk("asdf %d\n",(int)para);
			GOLDFISH_LED_WRITE(data, (int)para*4,0x0);
			break;
		case CMD3:
			printk("qwer %d\n",(int)para);
			GOLDFISH_LED_WRITE(data, (int)para*4,0x2);
			break;
		case CMD4:
			printk("qwer %d\n",(int)para);
			GOLDFISH_LED_WRITE(data, (int)para*4,0x3);
			break;
		case CMD5:
			printk("qwer %d\n",(int)para);
			GOLDFISH_LED_WRITE(data, (int)para*4,0x4);
			break;
		case CMD6:
			printk("qwer %d\n",(int)para);
			GOLDFISH_LED_WRITE(data, (int)para*4,0x5);
			break;
		case CMD7:
			printk("qwer %d\n",(int)para);
			GOLDFISH_LED_WRITE(data, (int)para*4,0x6);
			break;

		default:
			break;
	};
	return 0;
}

static const struct file_operations led_fops = {
	.owner = THIS_MODULE,
	.read = led_read,
	.write = led_write,
	.unlocked_ioctl = led_ioctl,
	.compat_ioctl = led_ioctl,
	.open = led_open,
	.release = led_release,
	.mmap = led_mmap,

};

static struct miscdevice led_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "led",
	.fops = &led_fops
};


asmlinkage long sys_led(int x){

	if(x==2){
		GOLDFISH_LED_WRITE(data, LED6, 0x1);
		GOLDFISH_LED_WRITE(data, LED5, 0x1);	
		GOLDFISH_LED_WRITE(data, LED4, 0x0);
		GOLDFISH_LED_WRITE(data, LED3, 0x0);
		GOLDFISH_LED_WRITE(data, LED2, 0x0);
		GOLDFISH_LED_WRITE(data, LED1, 0x0);
		GOLDFISH_LED_WRITE(data, LED0, 0x0);	
	}
	
	if(x == 1){
		GOLDFISH_LED_WRITE(data, LED6, 0x1);		
		GOLDFISH_LED_WRITE(data, LED5, 0x0);	
		GOLDFISH_LED_WRITE(data, LED4, 0x0);
		GOLDFISH_LED_WRITE(data, LED3, 0x0);
		GOLDFISH_LED_WRITE(data, LED2, 0x0);
		GOLDFISH_LED_WRITE(data, LED1, 0x0);
		GOLDFISH_LED_WRITE(data, LED0, 0x0);	
	
	}
	
	if(x==0){
		GOLDFISH_LED_WRITE(data, LED6, 0x0);
		GOLDFISH_LED_WRITE(data, LED5, 0x0);	
		GOLDFISH_LED_WRITE(data, LED4, 0x0);
		GOLDFISH_LED_WRITE(data, LED3, 0x0);
		GOLDFISH_LED_WRITE(data, LED2, 0x0);
		GOLDFISH_LED_WRITE(data, LED1, 0x0);
		GOLDFISH_LED_WRITE(data, LED0, 0x0);	
	}



	return 0;

}


static int goldfish_led_probe(struct platform_device *pdev)
{
	int ret;
	struct resource *r;


	printk(KERN_ERR "led probe started\n");
	data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
	if (data == NULL)
		return -ENOMEM;

	r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (r == NULL) {
		dev_err(&pdev->dev, "platform_get_resource failed\n");
		return -ENODEV;
	}

	if(request_mem_region(r->start, resource_size(r), "led")==NULL){
		printk(KERN_INFO "register led fail\n");
		return -EBUSY;
	}

	misc_register(&led_dev);
	data->reg_base = devm_ioremap(&pdev->dev, r->start, resource_size(r));
	if (data->reg_base == NULL) {
		dev_err(&pdev->dev, "unable to remap MMIO\n");
		return -ENOMEM;
	}

	printk(KERN_ERR "led probe finished\n");

	GOLDFISH_LED_WRITE(data, LED0, 0x0);
	GOLDFISH_LED_WRITE(data, LED1, 0x1);
	GOLDFISH_LED_WRITE(data, LED2, 0x2);
	GOLDFISH_LED_WRITE(data, LED3, 0x3);
	GOLDFISH_LED_WRITE(data, LED4, 0x4);
	GOLDFISH_LED_WRITE(data, LED5, 0x5);
	GOLDFISH_LED_WRITE(data, LED6, 0x6);

	return 0;
}

static int goldfish_led_remove(struct platform_device *pdev)
{
	return 0;
}


static const struct of_device_id goldfish_led_of_match[] = {
	{ .compatible = "generic,goldfish_led", },
	{},
};
MODULE_DEVICE_TABLE(of, goldfish_led_of_match);

static const struct acpi_device_id goldfish_led_acpi_match[] = {
	{ "GFSH0001", 0 },
	{ },
};
MODULE_DEVICE_TABLE(acpi, goldfish_led_acpi_match);


static struct platform_driver goldfish_led_device = {
	.probe		= goldfish_led_probe,
	.remove		= goldfish_led_remove,
	.driver = {
		.name = "goldfish_led",
		.of_match_table = goldfish_led_of_match,
		.acpi_match_table = ACPI_PTR(goldfish_led_acpi_match),
	}
};
module_platform_driver(goldfish_led_device);


MODULE_AUTHOR("Jinkyu Jeong wowzerjk@gmail.com");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Led driver for the Goldfish emulator");
