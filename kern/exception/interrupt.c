#include "interrupt.h"
#include "puthex.h"
#include <drivers/serial/uart.h>
#include <config.h>
#include <asm/io.h>
#include <drivers/clock/ptc-a9mpcore.h>
#include <syscalls/syscalls.h>

#define ICD_OFFSET 0x1000
#define ICC_OFFSET 0x0100

#define ICDDCR (MPCORE_PHYSBASE + ICD_OFFSET)
#define ICDSER0 (MPCORE_PHYSBASE + ICD_OFFSET + 0x100)

#define ICCICR (MPCORE_PHYSBASE + ICC_OFFSET)
#define ICCPMR (MPCORE_PHYSBASE + ICC_OFFSET + 0x004)
#define ICCIAR (MPCORE_PHYSBASE + ICC_OFFSET + 0x00C)
#define ICCEOIR (MPCORE_PHYSBASE + ICC_OFFSET + 0x010)

void interrupt_init() {
	init_IRQ_SP();
	init_SVC_SP();
	init_abort_SP();
	enable_peripheral_interrupt();
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

void enable_peripheral_interrupt() {
	out32(ICDDCR, 0x1);
	out32(ICCICR, 0x1);
	//enable private timer interrupt
	out32(ICDSER0, 0x20000000);

	u32 reg_val = in32(ICCPMR);
	uart_spin_puts("ICCPMR = ");
	puthex(reg_val);

	out32(ICCPMR, 0x80);
}

void C_SVC_handler(unsigned number, unsigned *reg) {
	uart_spin_puts("SVC handler.\r\n");
	enter_sys_mode();
	u32 tmp_sp, tmp_lr;
	asm volatile(
		"mov %0, sp\r\n"
		"mov %1, lr"
		:"=r"(tmp_sp), "=r"(tmp_lr));
	switch(number) {
		case 1:
			break; //SVC number 1 code
		default:
			system_call(reg);
	}
	uart_spin_puts("Finish system call!\r\n");
	// uart_spin_getbyte();
	asm volatile(
		"mov sp, %0\r\n"
		"mov lr, %1"
		::"r"(tmp_sp), "r"(tmp_lr));
	enter_svc_mode();
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

void C_IRQ_handler(u32 old_lr) {
	enter_sys_mode();
	u32 tmp_lr, tmp_sp;
	asm volatile(
		"mov %0, sp\r\n"
		"mov %1, lr"
		:"=r"(tmp_sp), "=r"(tmp_lr));
	uart_spin_puts("IRQ abort handler.\r\n");
	u32 interrupt_ID = in32(ICCIAR);
	uart_spin_puts("Interrupt ID = ");
	puthex(interrupt_ID);
	if (interrupt_ID == 29) { // private timer
		uart_spin_puts("Private Timer interupt\r\n");
		out32(ICCEOIR, 29);
	} else {
		out32(ICCEOIR, interrupt_ID);
	}
	// uart_spin_getbyte();
	asm volatile(
		"mov sp, %0\r\n"
		"mov lr, %1"
		::"r"(tmp_sp), "r"(tmp_lr));
	enter_irq_mode();
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