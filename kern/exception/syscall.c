#include "puthex.h"
#include "interrupt.h"
#include <drivers/serial/uart.h>

void system_call(unsigned number) {
	uart_spin_puts("system call.\r\n");
	enter_sys_mode();
	switch(number) {
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
	}
}