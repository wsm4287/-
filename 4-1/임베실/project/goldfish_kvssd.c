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
#include <linux/mutex.h>
#include <linux/wait.h>
#include <linux/spinlock.h>
#include <linux/file.h>

#define STATUS_REG		0x00
#define CMD_REG			0x04
#define KEY_REG			0x08
#define VALUE_REG			0x0c

#define CMD_PUT				3
#define CMD_GET				4
#define CMD_ERASE				5
#define CMD_EXIST				6

#define DEV_BUSY		1
#define DEV_READY		0

#define WAIT_FOR_COMPLETION	1

static wait_queue_head_t wait_q;
static int condition = 0;
static spinlock_t wait_q_lock;

static uint32_t key[4];
static uint32_t value[PAGE_SIZE/sizeof(uint32_t)];

struct goldfish_kvssd_data {
	void __iomem *reg_base;
};

static struct goldfish_kvssd_data *data;

static irqreturn_t goldfish_kvssd_handler(int irq, void *dev_id)
{
	spin_lock(&wait_q_lock);
	condition = 1;
	wake_up(&wait_q);
	spin_unlock(&wait_q_lock);

	return IRQ_HANDLED;
}


#define PAGE_SHIFT	12
#define PAGE_REMAIN	0xfff

static int goldfish_kvssd_remove(struct platform_device *pdev)
{
	return 0;
}

static int kvssd_open(struct inode *inode, struct file *file) {
	printk(KERN_INFO "kvssd file is opened\n");

	return 0;
}

static int kvssd_release(struct inode *inode, struct file *file) {
	printk(KERN_INFO "kvssd file is close\n");

	return 0;
}

static void kvssd_copy_from_parameter (unsigned long para, uint32_t *v, int len) {
	int i;

	for(i = 0; i < len; i++) {
		v[i] = *(uint32_t *)(para + sizeof(uint32_t) * i);
	}
}

static void kvssd_copy_to_parameter (unsigned long para, uint32_t *v, int len) {
	int i;

	for(i = 0; i < len; i++) {
		*(uint32_t *)(para + sizeof(uint32_t) * i) = v[i];
	}
}

/* User should address of key and value 
 * 	ex. user.c
 *
 * 	struct ioctl_env {
 * 		uint32_t key[4];
 * 		uint32_t value[1024];
 * 	};
 *
 * 	int main(int argc, char *argv[]) {
 *	 	struct ioctl_env env;
 *		//.... setup key and value of env
 *		//.... open file
 *		ioctl(fd, CMD_PUT, &env);	//pass address of env to kernel
 *		return 0;
 *	}
 * 											
*/
static int kvssd_ioctl (unsigned int cmd, unsigned long para) {
	int i;
	int ret;

	switch (cmd) {
		case CMD_PUT:
			kvssd_copy_from_parameter(para, key, sizeof(key) / sizeof(uint32_t));
			kvssd_copy_from_parameter(para + sizeof(key), value, sizeof(value) / sizeof(uint32_t));

			while(readl(data->reg_base + STATUS_REG) != DEV_READY);

			spin_lock_irq(&wait_q_lock);
			condition = 0;

			for(i = 0; i < sizeof(key) / sizeof(uint32_t); i++) {
				writel(key[i], data->reg_base + KEY_REG); 
			}
			for(i = 0; i < sizeof(value) / sizeof(uint32_t); i++) {
				writel(value[i], data->reg_base + VALUE_REG);
			}

			writel(CMD_PUT, data->reg_base + CMD_REG);

			wait_event_lock_irq(wait_q, condition, wait_q_lock);
			spin_unlock_irq(&wait_q_lock);
			
			ret = sizeof(value);
			break;
		case CMD_GET:
			kvssd_copy_from_parameter(para, key, sizeof(key) / sizeof(uint32_t));

			while(readl(data->reg_base + STATUS_REG) != DEV_READY);

			spin_lock_irq(&wait_q_lock);
			condition = 0;

			for(i = 0; i < sizeof(key) / sizeof(uint32_t); i++) {
				writel(key[i], data->reg_base + KEY_REG);
			}
			writel(CMD_GET, data->reg_base + CMD_REG);

			wait_event_lock_irq(wait_q, condition, wait_q_lock);
			spin_unlock_irq(&wait_q_lock);
	
			if(readl(data->reg_base + KEY_REG)) {
				for(i = 0; i < sizeof(value) / sizeof(uint32_t); i++) {
					value[i] = readl(data->reg_base + VALUE_REG);
				}
			}

			for(i = 0; i < sizeof(key) / sizeof(uint32_t); i++) {
				writel(key[i], data->reg_base + STATUS_REG);
			}

			kvssd_copy_to_parameter(para + sizeof(key), value, sizeof(value) / sizeof(uint32_t));

			ret = sizeof(value);
			break;
		case CMD_EXIST:
			kvssd_copy_from_parameter(para, key, sizeof(key) / sizeof(uint32_t));

			while(readl(data->reg_base + STATUS_REG) != DEV_READY);

			spin_lock_irq(&wait_q_lock);
			condition = 0;

			for(i = 0; i < sizeof(key) / sizeof(uint32_t); i++) {
				writel(key[i], data->reg_base + KEY_REG);
			}
			writel(CMD_EXIST, data->reg_base + CMD_REG);

			wait_event_lock_irq(wait_q, condition, wait_q_lock);
			spin_unlock_irq(&wait_q_lock);

			ret = readl(data->reg_base + KEY_REG);

			for(i = 0; i < sizeof(key) / sizeof(uint32_t); i++) {
				writel(key[i], data->reg_base + STATUS_REG);
			}

			break;
		case CMD_ERASE:
			kvssd_copy_from_parameter(para, key, sizeof(key) / sizeof(uint32_t));

			while(readl(data->reg_base + STATUS_REG) != DEV_READY);

			spin_lock_irq(&wait_q_lock);
			condition = 0;

			for(i = 0; i < sizeof(key) / sizeof(uint32_t); i++) {
				writel(key[i], data->reg_base + KEY_REG);
			}
			writel(CMD_ERASE, data->reg_base + CMD_REG);

			wait_event_lock_irq(wait_q, condition, wait_q_lock);
			spin_unlock_irq(&wait_q_lock);

			ret = true;
			break;
	};

	return ret;
}



asmlinkage long sys_kvssd(unsigned int cmd, unsigned long para){

	int ret = kvssd_ioctl(cmd, para);

	return ret;

}


static const struct file_operations kvssd_fops = {
	.owner = THIS_MODULE,
	.open = kvssd_open,
	.release = kvssd_release,
	.unlocked_ioctl = kvssd_ioctl,
	.compat_ioctl = kvssd_ioctl,
};

static struct miscdevice kvssd_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "kvssd",
	.fops = &kvssd_fops
};

static int goldfish_kvssd_probe(struct platform_device *pdev)
{
	int ret;
	struct resource *r;
	int error;

	printk(KERN_ERR "kvssd probe started\n");
	data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
	if (data == NULL)
		return -ENOMEM;

	r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (r == NULL) {
		dev_err(&pdev->dev, "platform_get_resource failed\n");
		return -ENODEV;
	}

	if(request_mem_region(r->start, resource_size(r), "kvssd")==NULL){
		printk(KERN_INFO "register kvssd fail\n");
		return -EBUSY;
	}

	misc_register(&kvssd_dev);

	data->reg_base = devm_ioremap(&pdev->dev, r->start, resource_size(r));
	if (data->reg_base == NULL) {
		dev_err(&pdev->dev, "unable to remap MMIO\n");
		return -ENOMEM;
	}

	error = devm_request_irq(&pdev->dev, platform_get_irq(pdev, 0), goldfish_kvssd_handler, 0, "goldfish_kvssd", NULL);
	init_waitqueue_head(&wait_q);
	spin_lock_init(&wait_q_lock);
	condition = 0;
	printk(KERN_ERR "kvssd probe finished\n");

	return 0;
}


static const struct of_device_id goldfish_kvssd_of_match[] = {
	{ .compatible = "generic,goldfish_kvssd", },
	{},
};
MODULE_DEVICE_TABLE(of, goldfish_kvssd_of_match);

static const struct acpi_device_id goldfish_kvssd_acpi_match[] = {
	{ "GFSH0001", 0 },
	{ },
};
MODULE_DEVICE_TABLE(acpi, goldfish_kvssd_acpi_match);


static struct platform_driver goldfish_kvssd_device = {
	.probe		= goldfish_kvssd_probe,
	.remove		= goldfish_kvssd_remove,
	.driver = {
		.name = "goldfish_kvssd",
		.of_match_table = goldfish_kvssd_of_match,
		.acpi_match_table = ACPI_PTR(goldfish_kvssd_acpi_match),
	}
};
module_platform_driver(goldfish_kvssd_device);


MODULE_AUTHOR("Jinkyu Jeong wowzerjk@gmail.com");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("kvssd driver for the Goldfish emulator");
