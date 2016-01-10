#ifndef _CONTEXT_SWITCH_H_
#define _CONTEXT_SWITCH_H_

static inline void context_switch_asm() {
	asm volatile(
		"stm sp, {r0-r14}^\r\n"
		"mrs r0, spsr\r\n"
		"stmdb sp, {r0, lr}\r\n"
		"mov sp, r12\r\n"
		"ldmdb sp, {r0, lr}\r\n"
		"msr spsr_cxsf, r0\r\n"
		"ldm sp, {r0-r14}^\r\n"
		"isb\r\n"
		"subs pc, lr, #4");
}

static inline void context_switch() {
	pcb_t* pcb = get_current_pcb();
	asm volatile("mov %0, sp":"=r"(pcb->kern_SP));	
	u32 new_pcb = next_pcb()->kern_SP;
	asm volatile(
		"mov r12, %\r\n"
		:"=r"(new_pcb)
		::"r12");
	context_switch_asm();
}

#endif