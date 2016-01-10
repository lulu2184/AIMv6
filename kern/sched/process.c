#include "process.h"
#include <vm/page_defines.h>
#include <vm/user_page.h>
#include <vm/slab_defines.h>
#include "elf_loader.h"
#include "scheduler.h"

unsigned max_pid = 0;

// return address of entry point of the new process
pcb_t* init_process(unsigned process_num) {
	pcb_t *pcb = (pcb_t*)obj_alloc(PCB_SIZE);
	// initialize kernel stack
	pcb->kern_SP = (unsigned)alloc_pages(1) + PAGE_SIZE - 4;
	// initialize page table
	pcb->page_table_addr = (unsigned)setup_page_table();
	// load elf
	unsigned addr = load_elf(process_num, (pte_t*)pcb->page_table_addr);

	pcb->pid = max_pid++;
	pcb->parent = 0;
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