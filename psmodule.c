#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/printk.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("PS_Module");
MODULE_AUTHOR("DMITRY KIRIENKO");


static int pid = 0;
module_param(pid, int, 0);


static void print_run_p(void)
{
        struct task_struct *task;
	
	for_each_process(task)
		pr_info("%s [%d]\n", task->comm, task->pid);
}

static void print_t(void)
{
	struct task_struct *taskpid;
	struct task_struct *thread;

	taskpid = get_pid_task(find_vpid(pid), PIDTYPE_PID);

        if(taskpid != NULL)
                for_each_thread(taskpid, thread)
                        pr_info("THREADS :  %s [%d]\n", thread->comm, thread->pid);
        else
                pr_info("Process with PID: %d isn't running\n", pid);
}

int init_module(void)
{
        printk("Module %s is loaded.\n", KBUILD_MODNAME);
	
	if(pid <= 0)
		print_run_p();
	else
		print_t();

	return 0;
}

void cleanup_module(void)
{
	printk("Module %s is unloaded.\n", KBUILD_MODNAME);
}
