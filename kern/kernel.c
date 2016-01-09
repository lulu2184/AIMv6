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

	print_cpsr();
	interrupt_init();
	uart_spin_puts("finish interrupt init\r\n");

	interrupt_enable();

	u32 tmp;
	uart_spin_puts("vector table : ");
	asm volatile(
		"ldr r0, =vector_table\r\n"
		"mov %0, r0\r\n"
		:"=r"(tmp));
	puthex(tmp);

	asm volatile(
		"mrc p15, 0, r0, c12, c0, 0\r\n"
		"mov %0, r0\r\n"
		:"=r"(tmp));
	puthex(tmp);

	uart_spin_puts("CSTR = ");
	asm volatile(
		"MRC p15, 0, r0, c1, c0, 0\r\n"
		"mov %0, r0"
		:"=r"(tmp));
	puthex(tmp);

	print_cpsr();

	uart_spin_puts("test interrupts\r\n");
	asm volatile("swi 0");
	uart_spin_puts("aroo\r\n");

	while (1);
}
