#include "puthex.h"
#include <drivers/serial/uart.h>

void system_call(unsigned number) {
	puthex("system call.\r\n");
	enter_sys_mode();
}