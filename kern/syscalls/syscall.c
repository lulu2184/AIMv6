#include "syscall.h"
#include "puthex.h"
#include <drivers/serial/uart.h>

void system_call(unsigned number) {
	uart_spin_puts("system call.\r\n");
	switch(number) {
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
	}
}