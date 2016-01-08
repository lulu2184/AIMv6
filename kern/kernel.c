#include "vm/page_defines.h"
#include "kernel.h"
#include "puthex.h"
#include "exception/interrupt.h"
#include "arch/armv7a-le/asm/irq.h"
#include <drivers/serial/uart.h>
#include <drivers/serial/uart-zynq7000.h>
#include <drivers/clock/gtc-a9mpcore.h>

void print_PC() {
	u32 tmp;
	uart_spin_puts("PC = ");
	asm volatile("mov %0 ,pc" : "=r"(tmp));
	puthex(tmp);
}

void print_SP() {
	u32 tmp;
	uart_spin_puts("SP = ");
	asm volatile("mov %0 ,sp" : "=r"(tmp));
	puthex(tmp);
}

int kernel_main() {
	uart_init();
	uart_enable();
	uart_spin_puts("Hello kernel!\r\n");
	//initialize devices
	interrupt_disable();
	print_cpsr();

	init_first_page_table();
	asm volatile(
		"ldr r0, =0x80000000\r\n"
		"add sp, sp, r0\r\n"
		"add fp, fp, r0\r\n");
	
	remove_low_mapping();
	print_PC();
	uart_spin_puts("Kernel space!\r\n");
	print_PC();
	alloc_init();
	print_SP();

	uart_spin_puts("TIME : \r\n");
	u64 gtc_time = gtc_get_time();
	puthex(gtc_time >> 32);
	puthex(gtc_time & 0xFFFFFFFF);

	print_cpsr();
	interrupt_init();
	uart_spin_puts("finish interrupt init\r\n");
	interrupt_enable();

	uart_spin_puts("TIME : \r\n");
	gtc_time = gtc_get_time();
	puthex(gtc_time >> 32);
	puthex(gtc_time & 0xFFFFFFFF);


	while (1);
}
