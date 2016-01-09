#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_

void interrupt_init();
void C_SVC_handler(unsigned number, unsigned *reg);
void C_prefetch_abort_handler();
void C_data_abort_handler();
void C_IRQ_handler();
void print_spsr();
void print_cpsr();

void system_call(unsigned number);

void enter_user_mode();

static inline void enter_sys_mode() {
	asm volatile(
		//"mov r1, lr\r\n"
		"mrs r0, cpsr\r\n"
		"orr r0, r0, #0xF\r\n"
		"msr cpsr, r0\r\n"
		:::"r0");
		// "isb\r\n"
		// "mov pc, r1"
		// ::: "r0", "r1");
}

static inline void enter_svc_mode() {
	asm volatile(
		"mrs r0, cpsr\r\n"
		"bic r0, r0, #0xF\r\n"
		"orr r0, r0, #0x3\r\n"
		"msr cpsr, r0\r\n"
		::: "r0");
}

void init_IRQ_SP();
void init_SVC_SP();
void init_abort_SP();

#endif