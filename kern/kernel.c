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
	// alloc_init();
	// char* addr = alloc_pages(2);
	// puthex((unsigned)addr);
	// free_pages(addr, 1);
	while (1);
}
