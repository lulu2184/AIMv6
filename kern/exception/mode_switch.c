#include "interrupt.h"

void enter_user_mode() {
	asm volatile(
		"mrs r0, cpsr\r\n"
		"bic r0, r0, #0xF\r\n"
		"msr cpsr, r0\r\n"
		"isb\r\n"
		"movs pc, lr\r\n");
}

void enter_sys_mode() {
	asm volatile(
		"mrs r0, cpsr\r\n"
		"orr r0, r0, #0xF\r\n"
		"msr cpsr, r0\r\n"
		"isb\r\n"
		"movs pc, lr\r\n"
		"isb\r\n");
}