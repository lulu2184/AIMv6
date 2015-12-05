#include "page_defines.h"
#include "puthex.h"
#include <string.h>
#include <drivers/serial/uart.h>

void fill_pme_common(pme_t *pme) {
	pme->type = 2;
	pme->XN = 0;
	pme->domain = 0;
	pme->zero1 = 0;
	pme->zero2 = 0;
	pme->NS = 0;
}

/**
 * In the first process, map VA <=> PA.
 **/
void init_mapping() {
	unsigned *table = (void *)PRESERVED_MEM_BASE;
	for (int i = 0; i < 0x2000; i++)
		table[i] = 0;
	
	/* mapping for non-preserved address PA <=> VA */
	pme_t *page_table = (void *)PRESERVED_MEM_BASE;
	pme_t *pme;
	for (unsigned *addr = 0; addr < (unsigned *)PYMEM_SIZE; addr += MEM_SECTION_SIZE >> 2) {
		pme = page_table + ((unsigned)addr >> MEM_SECTION_SHIFT);
		fill_pme_common(pme);
		pme->B = 0;			
		pme->C = 0;			
		pme->AP_L = 0x2;	//No user mode write AP: 011
		pme->TEX = 0x0; 	
		pme->AP_H = 0x0; 	//No user mode write
		pme->S = 0x1;		//sharable
		pme->ng = 0;		//global
		pme->base = (unsigned)addr >> MEM_SECTION_SHIFT;
	}

	/* mapping for preserved and non-preserved address PA <=> VA + KERN_BASE*/
	page_table = (void *)PRESERVED_MEM_BASE + (KERN_BASE >> (MEM_SECTION_SHIFT - 2));
	for (unsigned *addr = 0; addr < (unsigned *)PYMEM_SIZE; addr += MEM_SECTION_SIZE >> 2) {
		pme = page_table + ((unsigned)addr >> MEM_SECTION_SHIFT);
		fill_pme_common(pme);
		pme->B = 0;			
		pme->C = 0;			
		pme->AP_L = 0x2;	//No user mode write AP: 001
		pme->TEX = 0x0; 	
		pme->AP_H = 0x0; 	//No user mode write
		pme->S = 0x1;		//sharable
		pme->ng = 0;		//global
		pme->base = (unsigned)addr >> MEM_SECTION_SHIFT;
	}
}

/**
 * Map virtual memory to external devices.
 * Address begins on EXTMEM_BASE.
 **/
void devices_mapping() {
	/* entry for external device */
	pme_t *page_table = (void *)PRESERVED_MEM_BASE;
	for (unsigned *addr = (unsigned *)EXTMEM_BASE; addr - MEM_SECTION_SIZE < addr; addr += MEM_SECTION_SIZE >> 2) {
		pme_t *pme = page_table + ((unsigned)addr >> MEM_SECTION_SHIFT);
		fill_pme_common(pme);
		pme->B = 0;			//device
		pme->C = 0;			//device
		pme->AP_L = 0x3;	//Privileged access only AP: 001
		pme->TEX = 0; 		//device
		pme->AP_H = 0x0;	//Privileged access only
		pme->S = 0x1;		//sharable
		pme->ng = 0;		//Non-global
		pme->base = (unsigned)addr >> MEM_SECTION_SHIFT;
	}
}


/**
 * After MMU enabled, remove mapping in user space.
**/
void remove_low_mapping() {
	pme_t *page_table = (void *)PRESERVED_MEM_BASE;
	pme_t *pme;
	for (unsigned *addr = 0; addr < (unsigned *)PYMEM_SIZE; addr += MEM_SECTION_SIZE >> 2) {
		pme = page_table + ((unsigned)addr >> MEM_SECTION_SHIFT);
		pme->type = 0;
	}
}

/**
 * Initialize mapping from virtual memory to physical memory
 * for the kernel.
 **/
void init_first_page_table() {
	asm volatile(
		"ldr r1, [fp, #0]\r\n"
		"ldr r0, =0x80000000\r\n"
		"add r0, r1, r0\r\n"
		"str r0, [fp, #0]\r\n"
	);

	init_mapping();
	devices_mapping();
	enable_mmu(); 	//assemble code in vm/enable_mmu.S
	uart_spin_puts("enabled MMU\r\n");
	unsigned tmp_pc;
	uart_spin_puts("Now, PC should run on kernel address! PC = ");
	asm volatile("mov %0 ,pc" : "=r"(tmp_pc));
	puthex(tmp_pc);
	remove_low_mapping();
}		
