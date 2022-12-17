obj-m :=helloworld.o

CROSS_COMPILE = 
CC = gcc

KERNELDIR ?= /usr/src/linux-headers-$(shell uname -r)
PWD := $(shell pwd)

modules:
	make -C $(KERNELDIR) M=$(PWD) modules

clean:
	rm -rf *.o *~ core .depend *.symvers .*.cmd *.ko *.mod *.order .tmp_version $(TARGET)