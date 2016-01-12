#include "context_switch.h"
#include "process.h"
#include <drivers/serial/uart.h>
#include "scheduler.h"

void context_switch() {
	pcb_t* pcb = get_current_pcb();
	asm volatile("mov %0, sp":"=r"(pcb->kern_SP));	
	pcb_t* new_pcb = next_pcb();
	asm volatile(
		"mov r11, %0\r\n"
		:"=r"(new_pcb->kern_SP)
		::"r11");
	u32 tmp;
	puthex(new_pcb->kern_SP);
	asm volatile(
		"stm sp, {r0-r14}^\r\n"
		"mrs r0, spsr\r\n"
		"stmdb sp, {r0, lr}\r\n"
		"mov sp, r11\r\n"
		"ldmdb sp, {r0, lr}\r\n"
		"msr spsr_cxsf, r0\r\n"
		// "ldm sp, {r0-r14}^\r\n"
		// "mov r0, %1\r\n"
		// "mcr p15, 0, r0, c2, c0, 0\r\n"
		// "isb\r\n"
		// "mov %0, lr\r\n"
		// // "subs pc, lr, #4"
		:"=r"(tmp)
		:"r"(new_pcb->page_table_addr));
	puthex(tmp);
	uart_spin_getbyte();
}