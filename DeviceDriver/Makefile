obj-m += DeviceDriverBluetooth.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

# Include Bluetooth headers (if necessary, adjust the path)
EXTRA_CFLAGS += -I/usr/include/bluetooth

all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean
