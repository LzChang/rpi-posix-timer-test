obj-m += hello.o

KERNEL :=/usr/src/linux-headers-4.19.57-v7+/ 
all:
	make -C $(KERNEL) M=$(PWD) modules

clean:
	make -C $(KERNEL) M=$(PWD) clean
