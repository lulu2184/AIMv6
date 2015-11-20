#include "page_defines.h"
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
	pme_t *pme = (void *)PRESERVED_MEM_BASE;
//	memset(pme, 0, PAGE_SIZE << 2);
	
	/* mapping for non-preserved address PA <=> VA */
	for (unsigned *addr = 0; addr < (unsigned *)PRESERVED_MEM_BASE; addr += MEM_SECTION_SIZE) {
		fill_pme_common(pme);
		pme->B = 0;			//Non-cache
		pme->C = 0;			//Non-cache
		pme->AP_L = 0x3;	//full access AP: 011
		pme->TEX = 0x1; 	//Normal memory
		pme->AP_H = 0x0; 	//full access
		pme->S = 0x0;		//Non-sharable
		pme->ng = 1;		//Non-global
		pme->base = (unsigned)addr >> MEM_SECTION_SHIFT;
		pme += 32;
	}

	/* mapping for preserved and non-preserved address PA <=> VA + KERN_BASE*/
	pme = (void *)PRESERVED_MEM_BASE + (KERN_BASE >> MEM_SECTION_SHIFT);
	for (unsigned *addr = 0; addr < (unsigned *)EXTMEM_BASE; addr += MEM_SECTION_SIZE) {
		fill_pme_common(pme);
		pme->B = 0;			//Non-cache
		pme->C = 0;			//Non-cache
		pme->AP_L = 0x1;	//Privileged access only AP: 001
		pme->TEX = 0x1; 	//Normal memory
		pme->AP_H = 0x0; 	//Privileged access only
		pme->S = 0x0;		//Non-sharable
		pme->ng = 1;		//Non-global
		pme->base = (unsigned)addr >> MEM_SECTION_SHIFT;
		pme += 32;
	}
}

/**
 * Map virtual memory to external devices.
 * Address begins on EXTMEM_BASE.
 **/
void devices_mapping() {
	/* entry for external device */
	pme_t *pme = (void *)PRESERVED_MEM_BASE + (EXTMEM_BASE >> MEM_SECTION_SHIFT);
	for (unsigned *addr = (unsigned *)EXTMEM_BASE; addr < (unsigned *)0xFFFFFFFF; addr += MEM_SECTION_SIZE) {
		pme->B = 1;			//device
		pme->C = 0;			//device
		pme->AP_L = 0x1;	//Privileged access only AP: 001
		pme->TEX = 0; 		//device
		pme->AP_H = 0x0;	//Privileged access only
		pme->S = 0x1;		//sharable
		pme->ng = 0;		//Non-global
		pme->base = (unsigned)addr >> MEM_SECTION_SHIFT;
		pme += 32;
	}
}

/**
 * Initialize mapping from virtual memory to physical memory
 * for the kernel.
 **/
void init_first_page_table() {
	init_mapping();
	devices_mapping();
	enable_mmu(); 	//assemble code in vm/enable_mmu.S
	unsigned tmp_pc;
	asm volatile("mov %0 ,r15" : "=r"(tmp_pc));
	uart_spin_printf("%X\n",tmp_pc);
}
