// #include "context_switch.h"
// #include "process.h"
// #include <drivers/serial/uart.h>
// #include "scheduler.h"


void aa();
// void context_switch(unsigned old_lr) {
// 	pcb_t* pcb = get_current_pcb();
// 	asm volatile("mov %0, sp":"=r"(pcb->kern_SP));	
// 	pcb_t* new_pcb = next_pcb();
// 	uart_spin_puts("context_switch\r\n");
// 	asm volatile(
// 		"mov lr, %3\r\n"
// 		"stm sp, {r0-r12, lr}^\r\n"
// 		"mrs r0, spsr\r\n"
// 		"stmdb sp, {r0, lr}\r\n"
// 		"mov %0, sp\r\n"

// 		"mov r0, #0\r\n"
// 		"mov r2, %1\r\n"
// 		"isb\r\n"
//  		"mcr p15, 0, r0, c8, c7, 0\r\n" //invalidate TLB
// 		"mcr p15, 0, r2, c2, c0, 0\r\n"
// 		"isb\r\n"
// 		"dsb\r\n"

// 		"mov sp, %2\r\n"
// 		"ldmdb sp, {r0, lr}\r\n"
// 		"msr spsr_cxsf, r0\r\n"
// 		"ldm sp, {r0-r12, lr}^\r\n"
// 		:"=r"(pcb->kern_SP)
// 		:"r"(new_pcb->page_table_addr), "r"(pcb->kern_SP), "r"(old_lr));
// }