#ifndef _PRINT_H_
#define _PRINT_H_

void print(char *str) {
	asm volatile(
		"mov r1, %0\r\n"
		"mov r0, #1\r\n"
		"swi 0"
		::"r"((unsigned)str));
}

void puthex(unsigned num) {
	asm volatile(
		"mov r1, %0\r\n"
		"mov r0, #2\r\n"
		"swi 0"
		::"r"(num));
}

#endif