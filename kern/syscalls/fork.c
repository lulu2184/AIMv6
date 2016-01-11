#include "syscalls.h"
#include <sched/scheduler.h>
#include <vm/page_defines.h>
#include <memcpy.h>

unsigned fork() {
	pcb_t* current_pcb = get_current_pcb();
	pcb_t* new_pcb = create_pcb();
	new_pcb->parent = current_pcb;

	// copy_pages(new_pcb, current_pcb);
	
	new_pcb->kern_SP = (unsigned)alloc_pages(1) + PAGE_SIZE - 4;
	memcpy((char*)(new_pcb->kern_SP & 0x3FFF), (char*)(current_pcb->kern_SP & 0x3FFF), PAGE_SIZE);
	asm volatile(
		"mov sp, %0\r\n" 
		"isb"
		::"r"(new_pcb->kern_SP));
}