#include "interrupt.h"
#include <drivers/serial/uart.h>
#include <vm/page_defines.h>

void enter_user_mode() {
	asm volatile(
		"mrs r0, cpsr\r\n"
		"bic r0, r0, #0xF\r\n"
		"msr cpsr, r0\r\n"
	);
}

static inline void enter_irq_mode() {
	asm volatile(
		"mov r1, lr\r\n"
		"mrs r0, cpsr\r\n"
		"bic r0, r0, #0xF\r\n"
		"orr r0, r0, #0x2\r\n"
		"msr cpsr, r0\r\n"
		"isb\r\n"
		"mov pc, r1"
		::: "r0", "r1");
}

void init_IRQ_SP() {
	unsigned addr = (unsigned)alloc_pages(4);
	addr +=  PAGE_SIZE << 2;
	addr -= 4;
	puthex(addr);
	//enter irq mode
	asm volatile(
		"mrs r0, cpsr\r\n"
		"bic r0, r0, #0xF\r\n"
		"orr r0, r0, #0x2\r\n"
		"msr cpsr, r0\r\n"
		"isb"
		::: "r0");
	asm volatile(
		"mov sp, %0\r\n"
		:: "r"(addr));
	// enter sys mode 
	asm volatile(
		"mrs r0, cpsr\r\n"
		"orr r0, r0, #0xF\r\n"
		"msr cpsr, r0\r\n"
		:::"r0");
	uart_spin_puts("modify irq SP\r\n");
}

void init_SVC_SP() {
	unsigned addr = (unsigned)alloc_pages(4);
	addr +=  PAGE_SIZE << 2;
	addr -= 4;
	puthex(addr);
	//enter svc mode
	asm volatile(
		"mrs r0, cpsr\r\n"
		"bic r0, r0, #0xF\r\n"
		"orr r0, r0, #0x3\r\n"
		"msr cpsr, r0\r\n"
		"isb"
		::: "r0");
	//modify SP
	asm volatile(
		"mov sp, %0\r\n"
		:: "r"(addr));
	// enter sys mode 
	asm volatile(
		"mrs r0, cpsr\r\n"
		"orr r0, r0, #0xF\r\n"
		"msr cpsr, r0\r\n"
		:::"r0");
	uart_spin_puts("modify svc SP\r\n");
}

void init_abort_SP() {
	unsigned addr = (unsigned)alloc_pages(4);
	addr +=  PAGE_SIZE << 2;
	addr -=  4;
	puthex(addr);
	//enter abort mode
	asm volatile(
		"mrs r0, cpsr\r\n"
		"bic r0, r0, #0xF\r\n"
		"orr r0, r0, #0x7\r\n"
		"msr cpsr, r0\r\n"
		"isb"
		::: "r0");
	//modify SP
	asm volatile(
		"mov sp, %0\r\n"
		:: "r"(addr));
	// enter sys mode 
	asm volatile(
		"mrs r0, cpsr\r\n"
		"orr r0, r0, #0xF\r\n"
		"msr cpsr, r0\r\n"
		:::"r0");
	uart_spin_puts("modify abort SP\r\n");
}