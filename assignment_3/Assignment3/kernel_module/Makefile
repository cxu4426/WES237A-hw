obj-m += CPUcntr.o 

all:
	sudo make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C /lib/modules/$(uname -r)/build M=$(pwd) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWM) clean

