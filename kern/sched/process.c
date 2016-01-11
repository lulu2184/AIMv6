#include "process.h"
#include <vm/page_defines.h>
#include <vm/user_page.h>
#include <vm/slab_defines.h>
#include "scheduler.h"
#include "elf_loader.h"

unsigned max_pid = 0;

// return address of entry point of the new process
unsigned init_process(unsigned process_num) {
	uart_spin_puts("2");
	pcb_t *pcb = (pcb_t*)obj_alloc(PCB_SIZE);
	// initialize kernel stack
	pcb->kern_SP = (unsigned)alloc_pages(1) + PAGE_SIZE - 4;
	// initialize page table
	pcb->page_table_addr = (unsigned)setup_page_table();
	// load elf
	unsigned addr = (unsigned)load_elf(process_num, (pte_t*)pcb->page_table_addr);

	pcb->pid = max_pid++;
	pcb->parent = 0;
	add_pcb(pcb);
	return addr;
}

pcb_t* create_pcb() {
	pcb_t* pcb = (pcb_t*)obj_alloc(PCB_SIZE);
	pcb->pid = max_pid++;
	add_pcb(pcb);
	return pcb;
}

void destory_process(unsigned process_num) {

}

void setup_idle_process() {
	pcb_t *pcb = (pcb_t*)obj_alloc(PCB_SIZE);
	pcb->page_table_addr = PRESERVED_MEM_BASE + 0x80000000;
	pcb->pid = max_pid++;

	pcb->parent = 0;
	add_pcb(pcb);
}