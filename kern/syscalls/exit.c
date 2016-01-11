#include "syscalls.h"
#include <drivers/serial/uart.h>

void exit(int code) {
	uart_spin_puts("enter exit code\r\n");
}