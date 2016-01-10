#ifndef _PANIC_H_
#define _PANIC_H_

#include <drivers/serial/uart.h>

static inline void panic(char * msg) {
	uart_spin_puts(msg);
	while (1);
}

#endif