#include "vm/page_defines.h"
#include "kernel.h"
#include "puthex.h"
#include <drivers/serial/uart.h>

/**
 * entry point of kernel
**/
int kernel_entry() {
	uart_spin_puts("Hello kernel!\r\n");
	//initialize devices

	init_first_page_table();
	unsigned tmp;
	asm volatile(
		"ldr fp, =0x80F00000\r\n"
		"mov sp, fp"
	);
	remove_low_mapping();
	uart_spin_puts("Kernel space!: PC = ");
	asm volatile("mov %0 ,pc" : "=r"(tmp));
	puthex(tmp);
	alloc_init();
	uart_spin_puts("SP = ");
	asm volatile("mov %0 ,sp" : "=r"(tmp));
	puthex(tmp);


	while (1);
}
