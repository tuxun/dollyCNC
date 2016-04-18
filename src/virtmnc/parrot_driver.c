/*
 * Linux 2.6 and 3.0 'parrot' sample device driver
 *
 * Copyright (c) 2011, Pete Batard <pete@akeo.ie>
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#define LINUX




/*IPL5X is a USB 2.0 device working at full speed.
It identifies itself on the system as a HID compatible device with the following IDs:
VENDOR ID
0x04D8
PRODUCT ID
0x00AA
USB input and output buffers length are 36 Bytes.
Polling time is set to 1ms.

Answers from machine always start with the first byte sent: 
It's the kind of order to execute (move,info, etc)*/


#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/types.h>
#include <linux/mutex.h>
#include <linux/kfifo.h>

#include "parrot_driver.h"

#include <linux/hid.h>





/* Module information */
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_VERSION(VERSION);
MODULE_LICENSE("GPL");
MODULE_SUPPORTED_DEVICE("virtmnc");
MODULE_SUPPORTED_DEVICE("realmnc");
/* Device variables */
static struct class* parrot_class = NULL;
static struct device* parrot_device = NULL;



static struct class* minicut_class = NULL;
static struct device* minicut_device = NULL;

static int minicut_major;
static int parrot_major;
/* Flag used with the one_shot mode */
static bool message_read;
/* A mutex will ensure that only one process accesses our device */
static DEFINE_MUTEX(parrot_device_mutex);
/* Use a Kernel FIFO for read operations */
static DECLARE_KFIFO(parrot_msg_fifo, char, PARROT_MSG_FIFO_SIZE);
/* This table keeps track of each message length in the FIFO */
static unsigned int parrot_msg_len[PARROT_MSG_FIFO_MAX];


/* The file_operation scructure tells the kernel which device operations are handled.
 * For a list of available file operations, see http://lwn.net/images/pdf/LDD3/ch03.pdf */
static struct file_operations fops = {
	read: parrot_device_read,
	open:  parrot_device_open,	
	write: parrot_device_write,
	release:  parrot_device_close
};

/* Read and write index for the table above */
static int parrot_msg_idx_rd, parrot_msg_idx_wr;



//0;virtual(parrot)
//1;minuct(IPL5X via hid)
//2;reprap(gcode via usb/serial)
//3;CNC(gcode ngc via parport/usb_serial)
//4;Universal Printer(plotter, laser?) hpgl via serial/parport/usb_serial
static int driver_mode;
static int driver_last_op;



//static MAJOR,MINOR attribution, to replace with the dynamic same.
//MKDEV(int 10, int 57);

//MKDEV(10,57);



/* Module parameters that can be provided on insmod */
static bool debug = true;	/* print extra debug info */
module_param(debug, bool, S_IRUGO | S_IWUSR);
static bool one_shot = true;	/* only read a single message after open() */
module_param(one_shot, bool, S_IRUGO | S_IWUSR);

static bool virtual_driver=true;



//an argument to the driver

module_param(virtual_driver, bool, 0);
MODULE_PARM_DESC(virtual_driver, "(v)irtual or (r)eal ");

 struct hid_device *virtmncd;//= *hid_allocate_device();
 struct hid_device *realmncd;//= *hid_allocate_device();

/* Placing data into the read FIFO is done through sysfs */
static ssize_t sys_add_to_fifo(struct device* dev, struct device_attribute* attr, const char* buf, size_t count)
{
	unsigned int copied;

	//dbg("fifoadd");

	if (kfifo_avail(&parrot_msg_fifo) < count) {
		dbg("not enough space left on fifo\n");
		return -ENOSPC;
	}
	if ((parrot_msg_idx_wr+1)%PARROT_MSG_FIFO_MAX == parrot_msg_idx_rd) {

		/* We've looped into our message length table */
		warn("message length table is full\n");
		return -ENOSPC;
	}

	/* The buffer is already in kernel space, so no need for ..._from_user() */
	copied = kfifo_in(&parrot_msg_fifo, buf, count);
	parrot_msg_len[parrot_msg_idx_wr] = copied;
	if (copied != count) {
		warn("short write detected\n");
	}
	parrot_msg_idx_wr = (parrot_msg_idx_wr+1)%PARROT_MSG_FIFO_MAX;

	return copied;
}

/* This sysfs entry resets the FIFO */
static ssize_t sys_reset(struct device* dev, struct device_attribute* attr, const char* buf, size_t count)
{
	//dbg("");

	/* Ideally, we would have a mutex around the FIFO, to ensure that we don't reset while in use.
	 * To keep this sample simple, and because this is a sysfs operation, we don't do that */
	kfifo_reset(&parrot_msg_fifo);
	parrot_msg_idx_rd = parrot_msg_idx_wr = 0;

	return count;
}

/* Declare the sysfs entries. The macros create instances of dev_attr_fifo and dev_attr_reset 
AND MUST BE PLACED ATFER sys_reset() and sys_add_to_fifo()!!!*/
static DEVICE_ATTR(virtfifo, S_IWUSR, NULL, sys_add_to_fifo);
static DEVICE_ATTR(virtreset, S_IWUSR, NULL, sys_reset);
//static DEVICE_ATTR(realfifo, S_IWUSR, NULL, sys_add_to_fifo);
//static DEVICE_ATTR(realreset, S_IWUSR, NULL, sys_reset);


//realmncd->path="/dev/parrot_virtmnc";

static int parrot_device_open(struct inode* inode, struct file* filp)
{
/*	dbg("opeing!!!");
printk("debug opening!!!");
	 Our sample device does not allow write access */
/*a faire dans write*/
/*
	if ( ((filp->f_flags & O_ACCMODE) == O_WRONLY)
	  || ((filp->f_flags & O_ACCMODE) == O_RDWR) ) {
		warn("VIRTUAL write access is a BETA FEATURE\n");
		//return -EACCES;
	}
*/
	/* Ensure that only one process has access to our device at any one time
 	* For more info on concurrent accesses, see http://lwn.net/images/pdf/LDD3/ch05.pdf */
	if (!mutex_trylock(&parrot_device_mutex)) {
		warn("another process is accessing the device\n");
		return -EBUSY;
	}

	message_read = false;
	return 0;
}

static int parrot_device_close(struct inode* inode, struct file* filp)
{
	//warn("parrot finely closed\n");
	mutex_unlock(&parrot_device_mutex);
	return 0;
}

static ssize_t parrot_device_read(struct file* filp, char __user *buffer, size_t length, loff_t* offset)
{
	int retval;
	unsigned int copied;

	/* The default from 'cat' is to issue multiple reads until the FIFO is depleted
	 * one_shot avoids that */
	if (one_shot && message_read)
		{
		//	dbg("oneshot");
			 return 0;
		}
	

	if (kfifo_is_empty(&parrot_msg_fifo)) {
		//warn("no message in fifo\n");
		return 0;
	}

	retval = kfifo_to_user(&parrot_msg_fifo, buffer, parrot_msg_len[parrot_msg_idx_rd], &copied);
	/* Ignore short reads (but warn about them) */

	if (parrot_msg_len[parrot_msg_idx_rd] != copied) {
		err("short read detected\n");
	}
	/* loop into the message length table */
	parrot_msg_idx_rd = (parrot_msg_idx_rd+1)%PARROT_MSG_FIFO_MAX;
	message_read = true;

	return retval ? retval : copied;
}

/* from http://www.tldp.org/LDP/lkmpg/2.4/html/c577.htm
   struct file_operations {
       struct module *owner;
       loff_t (*llseek) (struct file *, loff_t, int);

       ssize_t (*read) (struct file *, char *, size_t, loff_t *);
       ssize_t (*write) (struct file *, const char *, size_t, loff_t *);

       int (*readdir) (struct file *, void *, filldir_t);
       unsigned int (*poll) (struct file *, struct poll_table_struct *);
       int (*ioctl) (struct inode *, struct file *, unsigned int, unsigned long);
       int (*mmap) (struct file *, struct vm_area_struct *);
       int (*open) (struct inode *, struct file *);
       int (*flush) (struct file *);
       int (*release) (struct inode *, struct file *);
       int (*fsync) (struct file *, struct dentry *, int datasync);
       int (*fasync) (int, struct file *, int);
       int (*lock) (struct file *, int, struct file_lock *);
    	 ssize_t (*readv) (struct file *, const struct iovec *, unsigned long,
          loff_t *);
    	 ssize_t (*writev) (struct file *, const struct iovec *, unsigned long,
          loff_t *);
    };
*see linux/fs.h
*/

static ssize_t parrot_device_write(struct file* filp, const char __user *buffer, size_t length, loff_t* offset)
{

ssize_t retlength;
	int nbc,i;
/*static ssize_t sys_add_to_fifo(struct device* dev, struct device_attribute* attr, const char* buf, size_t count)*/
retlength=sys_add_to_fifo(parrot_device,  NULL, buffer, length);



//dbg("fifoadd:");
nbc=length/sizeof(char);
//boucle debug
/*
for (i=0;i<nbc;i++)
	{printk("%i %c\n",nbc, *(buffer+i*(sizeof(char))));}
*/

//warning noyau output le msg recu par parrot dans une console via "dmesg"
for (i=0;i<nbc;i++)
	{printk("%c", *(buffer+i*(sizeof(char))));}
//printk("\n");
//usertokfifo?
	//!\retval = kfifo_to_user(&parrot_msg_fifo, buffer, parrot_msg_len[parrot_msg_idx_rd], &copied);
	

	message_read = true;

	return retlength;

}
//was I drunk or on a very good website?
void hidinput_hid_event(struct hid_device *devin, struct hid_field *field, struct hid_usage *usag, __s32 what)
	{
dbg("Youhou! hid event ;)\n");
	}

	int probe(struct hid_device *dev, const struct hid_device_id *id){return 0;}
;


/*return true if usb_device 0048x00aa found...*/
int exist_realmnc(void)
	{
	return 0;
}


//module_int crée un /dev/machine  comme suit:
//si  une minicut est trouvé: /dev/minicut_realmnc
//si on est on mode virtuel: si /dev/parrot_virtmnc



/* Module initialization and release */
static int __init parrot_module_init(void)
{
int ret1=0;
	int retval;
realmncd=NULL;
//virtmncd= hid_allocate_device();
///sys/devices/pci0000:00/0000:00:02.0/backlight/acpi_video0/brightness
realmncd= hid_allocate_device();
/*
if(hid_enumerate(0,0)!=-1)
{
	dbg("hid_starting...\n");
}

else{	dbg("failing to init hid... \n");
}*/
//realmncd->name="/dev/parrot_virtmnc";

/*
__u32 vendor;							
	__u32 product;							
int minor;						

	int open;						
	char name[128];							
	char phys[64];						
	char uniq[64];						
*/

if (realmncd>-1)
		{
								//info("hid_connect OK\n");
		/*		dbg("struct device_name: %s\n", realmncd->uniq);
		err("struct device_name: %s\n", realmncd->phys);
		err("struct device_name: %s\n", realmncd->name);//dbg("hidinput_connect: 1!");
		*/
ret1=1;
}		
	else 
	{
					//no real
ret1=0;
	}
	

	/*if (exist_realmnc())
		{
			dbg("realmnc!");
		}		
	else 
	{
					dbg("virtmnc!");
	}
*/
/*
if(hid_enumerate(0,0)!=NULL)
{
	dbg("hid_starting...\n");
}
else{	dbg("and failing to init hid... \n");
}
*/						//info("hid_connect OK\n");
		/*		dbg("struct device_name: %s\n", realmncd->uniq);
		err("struct device_name: %s\n", realmncd->phys);
		err("struct device_name: %s\n", realmncd->name);//dbg("hidinput_connect: 1!");
		*/
if (ret1)
		{
	//.1
					/* First, see if we can dynamically allocate a major for our device */
	minicut_major = register_chrdev(0, REALDEVICE_NAME, &fops);
	if (minicut_major < 0) {
		err("failed to dynamically register device: error %d\n", minicut_major);
		retval = minicut_major;
		//goto failed_chrdevreg;
	}
else {
		// /dev/minicut_virtmnc OK!
		info("v%s just registered REAL HID /dev/%s_%s\n", VERSION,CLASS_NAME,VIRTDEVICE_NAME);
}
	//.2
	//need to tie to libhid?
	/* We can either tie our device to a bus (existing, or one that we create)
	 * or use a "virtual" device class. For this example, we choose the latter */
	minicut_class = class_create(THIS_MODULE, MNCCLASS_NAME);
	if (IS_ERR(minicut_class)) {
		err("failed to register device class '%s'\n", MNCCLASS_NAME);
		retval = PTR_ERR(minicut_class);
		//goto failed_classreg;
	}
	//.3
	/* With a class, the easiest way to instantiate a device is to call device_create() */
	minicut_device = device_create(minicut_class, NULL, MKDEV(minicut_major, 0), NULL, MNCCLASS_NAME "_" REALDEVICE_NAME);
	if (IS_ERR(minicut_device)) {
		err("failed to create device '%s_%s'\n", MNCCLASS_NAME, REALDEVICE_NAME);
		retval = PTR_ERR(minicut_device);
		//goto failed_devreg;
	}

	//.4
	/* Now we can create the sysfs endpoints (don't care about errors).
	 * dev_attr_fifo and dev_attr_reset come from the DEVICE_ATTR(...) earlier */
	retval = device_create_file(parrot_device, &dev_attr_virtfifo);
	if (retval < 0) {
		warn("failed to create write /sys endpoint - continuing without\n");
	}
	retval = device_create_file(parrot_device, &dev_attr_virtreset);
	if (retval < 0) {
		warn("failed to create reset /sys endpoint - continuing without\n");
	}
	//no mutex, normalemment la libhid gere le dev a partir de là
	//mutex_init(&parrot_device_mutex);
	/* This device uses a Kernel FIFO for its read operation */
	
	//no need here?
	//INIT_KFIFO(parrot_msg_fifo);
	//parrot_msg_idx_rd = parrot_msg_idx_wr = 0;
	//fin init mode real (minicut)

}		
	else 
	{
					dbg("no realmnc\n");
	//.1
	/* First, see if we can dynamically allocate a major for our device */
	parrot_major = register_chrdev(0, VIRTDEVICE_NAME, &fops);
	if (parrot_major < 0) {
		err("failed to dynamically register device: error %d\n", parrot_major);
		retval = parrot_major;
		goto failed_chrdevreg;
	}
else {
		// /dev/minicut_virtmnc OK!
		info("v%s just registered virtual /dev/%s_%s\n", VERSION,CLASS_NAME,VIRTDEVICE_NAME);
		
}
	//.2
	/* We can either tie our device to a bus (existing, or one that we create)
	 * or use a "virtual" device class. For this example, we choose the latter */
	parrot_class = class_create(THIS_MODULE, CLASS_NAME);
	if (IS_ERR(parrot_class)) {
		err("failed to register device class '%s'\n", CLASS_NAME);
		retval = PTR_ERR(parrot_class);
		goto failed_classreg;
	}
	//.3
	/* With a class, the easiest way to instantiate a device is to call device_create() */
	parrot_device = device_create(parrot_class, NULL, MKDEV(parrot_major, 0), NULL, CLASS_NAME "_" VIRTDEVICE_NAME);
	if (IS_ERR(parrot_device)) {
		err("failed to create device '%s_%s'\n", CLASS_NAME, VIRTDEVICE_NAME);
		retval = PTR_ERR(parrot_device);
		goto failed_devreg;
	}
	//.4
	/* Now we can create the sysfs endpoints (don't care about errors).
	 * dev_attr_fifo and dev_attr_reset come from the DEVICE_ATTR(...) earlier */
	retval = device_create_file(parrot_device, &dev_attr_virtfifo);
	if (retval < 0) {
		warn("failed to create write /sys endpoint - continuing without\n");
	}
	retval = device_create_file(parrot_device, &dev_attr_virtreset);
	if (retval < 0) {
		warn("failed to create reset /sys endpoint - continuing without\n");
	}
hid_device_io_start(parrot_device);

	mutex_init(&parrot_device_mutex);
	/* This device uses a Kernel FIFO for its read operation */
	INIT_KFIFO(parrot_msg_fifo);
	parrot_msg_idx_rd = parrot_msg_idx_wr = 0;
	//fin init mode virtuel (parrot)
	}
	return 0;

/*un bon vieux GOTO
*ne sufit plus! voir  parrot_module_exit()*/
failed_devreg:
	class_unregister(parrot_class);
	class_destroy(parrot_class);
failed_classreg:
	unregister_chrdev(parrot_major, VIRTDEVICE_NAME);
failed_chrdevreg:

/*un bon vieux -1 pour dire que parrot_module_init a échoué a allouer le device*/
	return -1;
/*end !*/
}

static void __exit parrot_module_exit(void)
{
//	dbg("");
	/*dev_att_vrt* sont attribués via les macros en debut de fichier*/
	//je sais plus pour je remove le deux, c'est strange
	device_remove_file(parrot_device, &dev_attr_virtfifo);
	device_remove_file(parrot_device, &dev_attr_virtreset);
	
	device_destroy(parrot_class, MKDEV(parrot_major, 0));
	
	class_unregister(parrot_class);
	class_destroy(parrot_class);
	unregister_chrdev(parrot_major, VIRTDEVICE_NAME);
}

/* Let the kernel know the calls for module init and exit */
module_init(parrot_module_init);
module_exit(parrot_module_exit);
