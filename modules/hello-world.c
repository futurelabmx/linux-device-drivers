// Linux Kernel Headers
#include </usr/include/linux/init.h>
        // This may not work on compiled kernels without headers
#include </usr/include/linux/module.h>

MODULE_LICENSE("DUAL BSD/GPL");

static int hello_init(void)
{
        printk(KERN_ALERT "Hello World\n");
        return 0;
}

static int hello_exit(void)
{
        printk(KERN_ALERT "Goodbye\n");
}

module_init(hello_init);
module_exit(hello_exit);
