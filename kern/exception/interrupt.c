#include "interrupt.h"
#include "puthex.h"
#include <drivers/serial/uart.h>

void interrupt_init() {
	asm volatile(
		"ldr r0, =vector_table\r\n"
		"ldr r1, =0x80000000\r\n"
		"add r0, r1, r0\r\n"
		"mcr p15, 0, r0, c12, c0, 0\r\n");
}

void C_SVC_handler(unsigned number, unsigned *reg) {
	uart_spin_puts("SVC handler.\r\n");
	print_spsr();
	print_cpsr();
	switch(number) {
		case 0:
			break; //SVC number 0 code
		case 1:
			break; //SVC number 1 code
		default:
			system_call(reg[0]);
	}
	print_spsr();
}

void C_prefetch_abort_handler() {
	uart_spin_puts("prefetch abort handler.\r\n");
}

void C_data_abort_handler() {
	uart_spin_puts("data abort handler.\r\n");
}

void C_IRQ_handler() {
	uart_spin_puts("IRQ abort handler.\r\n");

}

void print_spsr() {
	int spsr;
	asm volatile(
		"mrs r0, spsr\r\n"
		"mov %0, r0" : "=r"(spsr));
	uart_spin_puts("SPSR=");
	puthex(spsr);
}

void print_cpsr() {
	int cpsr;
	asm volatile(
		"mrs r0, cpsr\r\n"
		"mov %0, r0" : "=r"(cpsr));
	uart_spin_puts("CPSR=");
	puthex(cpsr);
}