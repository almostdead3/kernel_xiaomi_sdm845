//SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/*
 * OxygenOS DT2W
 *
 * 
 */

#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/seq_file.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("testing");
MODULE_DESCRIPTION("oxygen os touch gesture");
MODULE_VERSION("0.0.1");

static int __init touch_oos_init(void) {
    static struct proc_dir_entry *tp_oos;
	int ret = 0;

	printk(KERN_INFO "oxygen os touch gesture initial");

	tp_oos = proc_symlink("tp_gesture", NULL, "touchpanel/gesture_enable");
	if (!tp_oos) {
		ret = -ENOMEM;
		printk(KERN_INFO "oxygen os touch gesture initial failed");
	} else
		printk(KERN_INFO "oxygen os touch gesture initialized");

	return ret;
}

static void __exit touch_oos_exit(void) {
	printk(KERN_INFO "oxygen os touch gesture exit");
}

module_init(touch_oos_init);
module_exit(touch_oos_exit);
