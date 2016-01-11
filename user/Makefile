prog1.elf:
	arm-unknown-eabi-gcc -c -O2 prog1.c -fpic -Wall -fno-builtin -nostdinc -nostdlib -march=armv7-a
	arm-unknown-eabi-ld -T prog1.ld prog1.o -o prog1.elf
	rm prog1.o

