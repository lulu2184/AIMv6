#ifndef _EXIT_H_
#define _EXIT_H_

void exit(int code) {
	asm volatile(
		"mov r1, %0\r\n"
		"mov r0, #3\r\n"
		"swi 0"
		::"r"(code));
}

#endif