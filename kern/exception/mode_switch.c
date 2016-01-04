#include "interrupt.h"

void enter_user_mode() {
	asm volatile(
		"mrs r0, cpsr\r\n"
		"ldr r1, =0xFFFFFFF0\r\n"
		"and r0, r1, r0\r\n"
		"msr cpsr, r0");
}