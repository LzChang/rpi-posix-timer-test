#include <linux/input.h>
#include <linux/device.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/jiffies.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/hrtimer.h>
#include <linux/irq.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/of.h>
#include <linux/input/mt.h>
#include <linux/interrupt.h>
#include <linux/miscdevice.h>

unsigned int timer_count=0;
struct hrtimer hrtimer_test_timer;
ktime_t m_kt;
int value=2000;
static enum hrtimer_restart hrtimer_test_timer_poll(struct hrtimer *timer)
{
printk("================timer_count=%d ==============\n",timer_count++);
hrtimer_forward(timer, timer->base->get_time(), m_kt);//hrtimer_forward(timer, now, tick_period);
//return HRTIMER_NORESTART;
return HRTIMER_RESTART;
}
int hrtimer_test_ioctl(struct inode *n, struct file *f, unsigned int cmd, unsigned long value){
}
ssize_t hrtimer_test_write(struct file *f, const char __user *buf, size_t t, loff_t *len){
int i;
int ret = -1;
printk("hrtimer Debug buf:%x size:%d\n",*buf,t);
if(*buf == '0'){
printk("hrtimer_start\n");
m_kt=ktime_set(value / 1000, (value % 1000) * 1000000);
hrtimer_start(&hrtimer_test_timer,m_kt, HRTIMER_MODE_REL);
}
else if(*buf == '1'){
printk("hrtimer_cancel\n");
hrtimer_cancel(&hrtimer_test_timer);
}
return t;
}
static const struct file_operations hrtimer_test_fops =
{
.owner = THIS_MODULE,
.write = hrtimer_test_write,
.unlocked_ioctl = hrtimer_test_ioctl,
};
struct miscdevice hrtimer_test_dev = {
.minor = MISC_DYNAMIC_MINOR,
.name = "hrtimer_test",
.fops = &hrtimer_test_fops,
};
static int __init hrtimer_test_init(void)
{
int ret;
ret = misc_register(&hrtimer_test_dev);
hrtimer_init(&hrtimer_test_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
hrtimer_test_timer.function = hrtimer_test_timer_poll;
return 0;
}
static void __exit hrtimer_test_exit(void)
{
misc_deregister(&hrtimer_test_dev);
}
module_init(hrtimer_test_init);
module_exit(hrtimer_test_exit);
MODULE_AUTHOR("hrtimer<hrtimer@hrtimer.cc>");
MODULE_LICENSE("GPL"); 
