#include "puthex.h"
#include "interrupt.h"
#include <drivers/serial/uart.h>

void system_call(unsigned number) {
	uart_spin_puts("system call.\r\n");
	// enter_sys_mode();
	// switch to sys mode
	asm volatile(
		//"mov r1, lr\r\n"
		"mrs r0, cpsr\r\n"
		"orr r0, r0, #0xF\r\n"
		"msr cpsr, r0\r\n"
		:::"r0");
	uart_spin_puts("sys mode\r\n");
	switch(number) {
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
	}
	// switch back to svc mode
	asm volatile(
		"mrs r0, cpsr\r\n"
		"bic r0, r0, #0xF\r\n"
		"orr r0, r0, #0x3\r\n"
		"msr cpsr, r0\r\n"
		::: "r0");
}