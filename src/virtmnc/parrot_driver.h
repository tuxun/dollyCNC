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

extern void hidinput_hid_event(struct hid_device *, struct hid_field *, struct hid_usage *, __s32);
extern void hidinput_report_event(struct hid_device *hid, struct hid_report *report);
extern int hidinput_connect(struct hid_device *hid, unsigned int force);
extern void hidinput_disconnect(struct hid_device *);

int hid_set_field(struct hid_field *, unsigned, __s32);
int hid_input_report(struct hid_device *, int type, u8 *, int, int);
int hidinput_find_field(struct hid_device *hid, unsigned int type, unsigned int code, struct hid_field **field);
struct hid_field *hidinput_get_led_field(struct hid_device *hid);
unsigned int hidinput_count_leds(struct hid_device *hid);
__s32 hidinput_calc_abs_res(const struct hid_field *field, __u16 code);
void hid_output_report(struct hid_report *report, __u8 *data);
u8 *hid_alloc_report_buf(struct hid_report *report, gfp_t flags);
struct hid_device *hid_allocate_device(void);
struct hid_report *hid_register_report(struct hid_device *device, unsigned type, unsigned id);
int hid_parse_report(struct hid_device *hid, __u8 *start, unsigned size);
struct hid_report *hid_validate_values(struct hid_device *hid,
				       unsigned int type, unsigned int id,
				       unsigned int field_index,
				       unsigned int report_counts);
int hid_open_report(struct hid_device *device);
int hid_check_keys_pressed(struct hid_device *hid);
int hid_connect(struct hid_device *hid, unsigned int connect_mask);
void hid_disconnect(struct hid_device *hid);
const struct hid_device_id *hid_match_id(struct hid_device *hdev,
					 const struct hid_device_id *id);
s32 hid_snto32(__u32 value, unsigned n);
 */

#define REALDEVICE_NAME "realmnc"
#define VIRTDEVICE_NAME "virtmnc"
#define CLASS_NAME "parrot"
#define MNCCLASS_NAME "minicut"
#define PARROT_MSG_FIFO_SIZE 512
#define PARROT_MSG_FIFO_MAX  36

#define AUTHOR "Tuxun <tuxun@funlab.fr>"
#define DESCRIPTION "'Minicut2D' parrot device driver"
#define VERSION "0.1B_testing"

/* We'll use our own macros for printk */
#define dbg(format, arg...) pr_info(CLASS_NAME ": %s: " format , __FUNCTION__ , ## arg)
#define info(format, arg...) pr_info(CLASS_NAME ": " format, ## arg)
#define warn(format, arg...) pr_warn(CLASS_NAME ": " format, ## arg)
#define err(format, arg...) pr_err(CLASS_NAME ": " format, ## arg)

#define module_hid_driver(__hid_driver) \
	module_driver(__hid_driver, hid_register_driver, \
		      hid_unregister_driver)
static ssize_t parrot_device_write(struct file* filp, const char __user *buffer, size_t length, loff_t* offset);
static ssize_t parrot_device_read(struct file* filp, char __user *buffer, size_t length, loff_t* offset);
static int parrot_device_close(struct inode* inode, struct file* filp);
static int parrot_device_open(struct inode* inode, struct file* filp);

