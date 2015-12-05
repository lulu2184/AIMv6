#include "vm/page_defines.h"
#include "kernel.h"
#include "puthex.h"
#include <drivers/serial/uart.h>

/**
 * entry point of kernel
**/
int kernel_entry() {
	uart_spin_puts("Hello kernel!\r\n");
	init_first_page_table();
	alloc_init();

	while (1);
}
