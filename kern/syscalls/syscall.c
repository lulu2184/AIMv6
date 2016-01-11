#include "syscalls.h"
#include "puthex.h"
#include <drivers/serial/uart.h>

void system_call(unsigned *reg) {
	uart_spin_puts("system call.\r\n");
	switch(reg[0]) {
		case 0:
			break;
		case 1:
			uart_spin_puts((char*)reg[1]);
			break;
		case 2:
			puthex(reg[1]);
			break;
		case 3:
			exit(reg[1]);
			break;
	}
}