#include "interrupt.h"
#include "puthex.h"
#include <drivers/serial/uart.h>

void interrupt_init() {
	init_IRQ_SP();
	init_SVC_SP();
	init_abort_SP();
	u32 tmp;
	asm volatile(
		"ldr r0, =vector_table\r\n"
		"ldr r1, =0x80000000\r\n"
		"add r0, r1, r0\r\n"
		"mcr p15, 0, r0, c12, c0, 0\r\n"
		"mov %0, r0"
		:"=r"(tmp));
	uart_spin_puts("interrupt init, vector_table = ");
	puthex(tmp);
}

void C_SVC_handler(unsigned number, unsigned *reg) {
	uart_spin_puts("SVC handler.\r\n");
	uart_spin_puts("old lr = ");
	puthex(reg[1]);
	print_cpsr();
	u32 tmp;
	uart_spin_puts("in SVC, LR = ");
	asm volatile("mov %0 ,lr" : "=r"(tmp));
	puthex(tmp);
	print_spsr();
	print_cpsr();
	uart_spin_puts("in SVC, SP=");
	puthex(tmp);
	switch(number) {
		case 0:
			break; //SVC number 0 code
		case 1:
			break; //SVC number 1 code
		default:
			system_call(reg[0]);
	}
	uart_spin_puts("Finish system call!\r\n");
	print_spsr();
	// print_SP();
	print_cpsr();
	uart_spin_getbyte();
}

void C_prefetch_abort_handler() {
	uart_spin_puts("prefetch abort handler.\r\n");
	u32 tmp;
	uart_spin_puts("in abort, LR = ");
	asm volatile("mov %0 ,lr" : "=r"(tmp));
	puthex(tmp);
	print_spsr();
	print_cpsr();
	uart_spin_puts("in abort, SP=");
	puthex(tmp);
	uart_spin_getbyte();
}

void C_data_abort_handler() {
	uart_spin_puts("data abort handler.\r\n");
	u32 tmp;
	asm volatile("mov %0, sp" : "=r"(tmp));
	uart_spin_puts("SP = ");
	puthex(tmp);
	asm volatile("mov %0, lr" : "=r"(tmp));
	uart_spin_puts("LR = ");
	puthex(tmp);
	uart_spin_getbyte();
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