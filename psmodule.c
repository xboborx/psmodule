#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/printk.h>

int init_module(void)
{
	struct task_struct *task;

        printk("Module %s is loaded.\n", KBUILD_MODNAME);
	for_each_process(task)
		pr_info("%s [%d]\n", task->comm, task->pid);
	return 0;
}

void cleanup_module(void)
{
	printk("Module %s is unloaded.\n", KBUILD_MODNAME);
}

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("PS_Module");
MODULE_AUTHOR("DMITRY KIRIENKO");
