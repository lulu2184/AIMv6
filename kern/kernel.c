#include "vm/page_defines.h"
#include "kernel.h"
#include "puthex.h"
#include "exception/interrupt.h"
#include "arch/armv7a-le/asm/irq.h"
#include <drivers/serial/uart.h>
#include <drivers/serial/uart-zynq7000.h>
#include <drivers/clock/ptc-a9mpcore.h>
#include "sched/process.h"
#include "vm/slab_defines.h"
#include <drivers/sd/sd-zynq7000.h>
#include "sched/context_switch.h"
#include "sched/scheduler.h"
#include "memcpy.h"

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

void test_svc() {
	uart_spin_puts("test interrupts\r\n");
	asm volatile("swi 0");
	uart_spin_puts("aroo\r\n");
}

void test_clock_interrupt() {
	uart_spin_puts("test clock interrupt\r\n");

	while (1) {
		u32 tmp = ptc_get_time();
		puthex(tmp);
	}
}

void single_proc_test() {
	unsigned addr = init_process(1);
	uart_spin_puts("proc entry point : ");
	puthex(addr);
	uart_spin_puts("[9EFD104c]");
	puthex(*(unsigned*)(0x9EFD104c));
	// enter_user_mode();
	pcb_t* pcb = get_current_pcb();
	unsigned pt_addr = pcb->page_table_addr + 0x80000000;
	puthex(pt_addr);
	uart_spin_puts("[9EFD104c]");
	puthex(*(unsigned*)(0x9EFD104c));
	puthex(*(unsigned*)(pcb->page_table_addr + 0x10));
	puthex(*(unsigned*)(pcb->page_table_addr + (PAGE_SIZE << 1) + 28));
	puthex(*(unsigned*)(0x9EFFC400));
	uart_spin_puts("[9EFD104c]");
	puthex(*(unsigned*)(0x9EFD104c));
	puthex(pcb->page_table_addr);
	puthex(pcb);
	asm volatile(
		// "mrs r0, spsr\r\n"
		// "bic r0, r0, #0xF\r\n"
		// "msr spsr, r0\r\n"
		"mov r0, %0\r\n"
		"mcr p15, 0, r0, c2, c0, 0\r\n"
		"isb\r\n"
		::"r"(pt_addr));
	puthex(pcb->kern_SP);
	asm volatile(
		"mov r0, %1\r\n"
		"mov sp, %0\r\n"
		"isb\r\n"
		::"r"(pcb->kern_SP), "r"(addr)
		:"r0");
	asm volatile(
		// "stmfd sp!, {%0}\r\n"
		// "ldmfd sp!, {pc}^\r\n"
		"mov pc, r0\r\n"
		"nop\r\n"
		"nop\r\n"
		:::"r0");
}

void single_proc_test_cts() {
	unsigned addr = init_process(1);
	pcb_t* pre_pcb = get_current_pcb();
	pcb_t* pcb = next_pcb();

	uart_spin_puts("try to jump to new process\r\n");

	// puthex(pcb->page_table_addr);
	// puthex(*(unsigned*)(pcb->page_table_addr + (0x4 << 2)));
	// puthex(*(unsigned*)(0x9EFFB400));
	// puthex(*(unsigned*)(pcb->page_table_addr + (0x808 << 2)));
	// puthex(*(unsigned*)(pcb->page_table_addr + (0x809 << 2)));

	unsigned pt_addr = pcb->page_table_addr + 0x80000000;
	// puthex(pt_addr);
	// puthex(addr);

	print_cpsr();

	asm volatile(
		"ldr lr, =happy_say_hello\r\n"
		"stm sp, {r0-r12, lr}^\r\n"
		"mrs r0, cpsr\r\n"
		"stmdb sp, {r0, lr}\r\n"
		"mov %0, sp\r\n"

		"mov r12, %2\r\n"
		"mov lr, %3\r\n"
		"stm r12, {r0-r12, lr}^\r\n"
		"mrs r0, cpsr\r\n"
		"bic r0, r0, #0xF\r\n"
		"stmdb r12, {r0, lr}\r\n"

		"mov r0, #0\r\n"
		"mov r2, %1\r\n"
		"isb\r\n"
 		"mcr p15, 0, r0, c8, c7, 0\r\n" //invalidate TLB
		"mcr p15, 0, r2, c2, c0, 0\r\n"
		"isb\r\n"
		"dsb\r\n"

		"mov sp, r12\r\n"
		"ldmdb sp, {r0, lr}\r\n"
		"msr spsr_cxsf, r0\r\n"
		"ldm sp, {r0-r12, pc}^\r\n"
		:"=r"(pre_pcb->kern_SP)
		:"r"(pt_addr), "r"(pcb->kern_SP), "r"(addr)
		:"r0", "r2", "r12");
}

void test_syscall() {
	uart_spin_puts("syscall test: [print 0x10] ");
	asm volatile(
		"mov r1, #0x10\r\n"
		"mov r0, #2\r\n"
		"swi 0");
}

void test_change_table() {
	uart_spin_puts("test change table\r\n");
	char* entry = setup_page_table();
	puthex(entry);
	char* kt_entry = (void *)(PRESERVED_MEM_BASE + (PAGE_SIZE << 1));
	memcpy(entry, kt_entry, PAGE_SIZE << 2);
	uart_spin_puts("before change table\r\n");
	entry += 0x80000000;
	puthex(entry);
	asm volatile(
		"mov r2, %0\r\n"
		"isb\r\n"
		"mcr p15, 0, r2, c2, c0, 0\r\n"
		"isb\r\n"
		"dsb\r\n"
		::"r"(entry));
}

void happy_say_hello() {
	while (1) {
		uart_spin_puts("[P0] I'm initialize process in kernel space\r\n");
	};
}

int kernel_main() {
	uart_init();
	uart_enable();
	sd_init();
	uart_spin_puts("Hello kernel!\r\n");
	//initialize devices
	interrupt_disable();
	int ret = sd_spin_init_mem_card();
	puthex(ret);

	print_cpsr();

	init_first_page_table();
	asm volatile(
		"ldr r0, =0x80000000\r\n"
		"add sp, sp, r0\r\n"
		"add fp, fp, r0\r\n"
		"add pc, pc, r0\r\n"
		"isb\r\n");
	
	uart_spin_puts("Now, PC should run on kernel address! ");
	print_PC();

	remove_low_mapping();
	print_PC();
	uart_spin_puts("Kernel space!\r\n");
	print_PC();
	alloc_init();
	slab_pools_init();
	print_SP();

	print_cpsr();
	interrupt_init();
	scheduler_init();
	uart_spin_puts("finish interrupt init\r\n");

	interrupt_enable();
	print_cpsr();
	ptc_init(0x200000);
	ptc_enable();
	// test_clock_interrupt();

	// test_change_table();
	// test_syscall();
	// test_svc();
	// single_proc_test();
	single_proc_test_cts();

	while (1) {
		uart_spin_puts("[P0] I'm initialize process in kernel space\r\n");
	};
}
