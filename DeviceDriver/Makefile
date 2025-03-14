obj-m += ControllerDriver.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
	gcc -o ButtonReading ButtonReading.c

clean:
	rm -rf *.o *.ko *.mod.* *.symvers *.order ButtonReading
