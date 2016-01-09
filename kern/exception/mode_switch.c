#include "interrupt.h"
#include <drivers/serial/uart.h>
#include <vm/page_defines.h>

void init_IRQ_SP() {
	unsigned addr = (unsigned)alloc_pages(4);
	addr +=  PAGE_SIZE << 2;
	addr -= 4;
	puthex(addr);
	enter_irq_mode();
	asm volatile("mov sp, %0\r\n" :: "r"(addr));
	enter_sys_mode();
	uart_spin_puts("modify irq SP\r\n");
}

void init_SVC_SP() {
	unsigned addr = (unsigned)alloc_pages(4);
	addr +=  PAGE_SIZE << 2;
	addr -= 4;
	puthex(addr);
	enter_svc_mode();
	asm volatile("mov sp, %0\r\n" :: "r"(addr));
	enter_sys_mode();
	uart_spin_puts("modify svc SP\r\n");
}

void init_abort_SP() {
	unsigned addr = (unsigned)alloc_pages(4);
	addr +=  PAGE_SIZE << 2;
	addr -=  4;
	puthex(addr);
	enter_abort_mode();
	asm volatile("mov sp, %0\r\n" :: "r"(addr));
	enter_sys_mode();
	uart_spin_puts("modify abort SP\r\n");
}