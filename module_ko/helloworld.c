#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/i2c.h>



int init_hellow_module(void)
{
    char buf[10]="string";
    char *after;
    unsigned long state;
    printk("start---------------------\n");
    if(1==1)
    {
        printk("start-----------------2----\n");

        state = simple_strtoul(buf, &after, 10);
    }
    return 0;
}

void exit_hellow_module(void)
{
    printk("over---------------------\n");
}
module_init(init_hellow_module);
module_exit(exit_hellow_module);
