TARGET = parrot_driver


# call from kernel build system

obj-m	:= $(TARGET).o
#uname -r ou a
KERNELDIR ?= /usr/src/linux-headers-$(shell uname -r)
PWD       := $(shell pwd)


#gcc hidapi.c -o hidapi.o -ludev
default: clean
	$(MAKE) -C $(KERNELDIR) SUBDIRS=$(PWD) modules
silent:
	$(MAKE) -s -C $(KERNELDIR) SUBDIRS=$(PWD) modules

#ok
clean:
	rm -rf *.o *.ko *~ core .depend *.mod.c .*.cmd .tmp_versions .*.o.d

depend .depend dep:
	$(CC) $(CFLAGS) -M *.c > .depend
	ifeq (.depend,$(wildcard .depend))
	include .depend
	endif

#ok
mod_load:
	@if [ -n "`lsmod | grep -s hid`" ]; then echo ""; else modprobe hid; fi
#	@if [ -n "`lsmod | grep -s hid`" ]; then echo -e "\e[92m/*******L0ad1ng H1D dr1v3r 0k*******”\e[0m/"; else echo -e "\e[91m/*******L0ad1ng dr1v3r F41L3D****”\e[0m/"; fi
	insmod $(TARGET).ko debug=1
#f5buF1gx

#ok
mod_unload:
	@if [ -n "`lsmod | grep -s $(TARGET)`" ]; then rmmod $(TARGET); echo "rmmod $(TARGET)"; fi

mod_reload:	mod_unload mod_load
	@if [ -n "`lsmod | grep -s $(TARGET)`" ]; then echo "*********rel0ad1ng dr1v3r 0k*******"; else echo "*********rel0ad1ng dr1v3r F41L3D****"; fi
