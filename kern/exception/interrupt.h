#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_

void interrupt_init();
void C_SVC_handler(unsigned number, unsigned *reg, unsigned old_lr);
void C_prefetch_abort_handler();
void C_data_abort_handler();
void C_IRQ_handler();
void print_spsr();
void print_cpsr();

void init_IRQ_SP();
void init_SVC_SP();
void init_abort_SP();

void enable_peripheral_interrupt();

static inline void enter_user_mode() {
	asm volatile(
		"isb\r\n"
		"mrs r0, cpsr\r\n"
		"bic r0, r0, #0xF\r\n"
		"msr cpsr, r0\r\n"
		"isb"
		:::"r0");
}

static inline void enter_sys_mode() {
	asm volatile(
		"isb\r\n"
		"mrs r0, cpsr\r\n"
		"orr r0, r0, #0xF\r\n"
		"msr cpsr, r0\r\n"
		"isb\r\n"
		:::"r0");
}

static inline void enter_svc_mode() {
	asm volatile(
		"isb\r\n"
		"mrs r0, cpsr\r\n"
		"bic r0, r0, #0xF\r\n"
		"orr r0, r0, #0x3\r\n"
		"msr cpsr, r0\r\n"
		"isb"
		::: "r0");
}

static inline void enter_irq_mode() {
	asm volatile(
		"isb\r\n"
		"mrs r0, cpsr\r\n"
		"bic r0, r0, #0xF\r\n"
		"orr r0, r0, #0x2\r\n"
		"msr cpsr, r0\r\n"
		"isb\r\n"
		::: "r0");
}

static inline void enter_abort_mode() {
	asm volatile(
		"isb\r\n"
		"mrs r0, cpsr\r\n"
		"bic r0, r0, #0xF\r\n"
		"orr r0, r0, #0x7\r\n"
		"msr cpsr, r0\r\n"
		"isb"
		::: "r0");
}

#endif