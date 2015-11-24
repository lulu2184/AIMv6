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
 * TODO: revise comments
 **/
void init_mapping() {
//	memset(pme, 0, PAGE_SIZE << 2);
	unsigned *table = (void *)PRESERVED_MEM_BASE;
	for (int i = 0; i < 0x2000; i++)
		table[i] = 0;
	
	/* mapping for non-preserved address PA <=> VA */
	pme_t *page_table = (void *)PRESERVED_MEM_BASE;
	pme_t *pme;
	for (unsigned *addr = 0; addr < (unsigned *)PYMEM_SIZE; addr += MEM_SECTION_SIZE >> 2) {
		pme = page_table + ((unsigned)addr >> MEM_SECTION_SHIFT);
		fill_pme_common(pme);
		pme->B = 0;			//Non-cache
		pme->C = 0;			//Non-cache
		pme->AP_L = 0x2;	//full access AP: 011
		pme->TEX = 0x0; 	//Normal memory
		pme->AP_H = 0x0; 	//full access
		pme->S = 0x1;		//Non-sharable
		pme->ng = 0;		//Non-global
		pme->base = (unsigned)addr >> MEM_SECTION_SHIFT;
	}

	/* mapping for preserved and non-preserved address PA <=> VA + KERN_BASE*/
	// pme = (void *)PRESERVED_MEM_BASE + (KERN_BASE >> MEM_SECTION_SHIFT) * 4;
	page_table = (void *)PRESERVED_MEM_BASE + (KERN_BASE >> (MEM_SECTION_SHIFT - 2));
	for (unsigned *addr = 0; addr < (unsigned *)PYMEM_SIZE; addr += MEM_SECTION_SIZE >> 2) {
		pme = page_table + ((unsigned)addr >> MEM_SECTION_SHIFT);
		fill_pme_common(pme);
		pme->B = 0;			//Non-cache
		pme->C = 0;			//Non-cache
		pme->AP_L = 0x2;	//Privileged access only AP: 001
		pme->TEX = 0x0; 	//Normal memory
		pme->AP_H = 0x0; 	//Privileged access only
		pme->S = 0x1;		//Non-sharable
		pme->ng = 0;		//Non-global
		pme->base = (unsigned)addr >> MEM_SECTION_SHIFT;
	}
}

/**
 * Map virtual memory to external devices.
 * Address begins on EXTMEM_BASE.
 **/
void devices_mapping() {
	/* entry for external device */
	// pme_t *pme = (void *)PRESERVED_MEM_BASE + (EXTMEM_BASE >> MEM_SECTION_SHIFT);
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
 * Initialize mapping from virtual memory to physical memory
 * for the kernel.
 **/
void init_first_page_table() {
	uart_spin_puts("Hello kernel!\r\n");
	init_mapping();
	devices_mapping();
	enable_mmu(); 	//assemble code in vm/enable_mmu.S
	uart_spin_puts("enabled MMU\r\nPC=");
	unsigned tmp_pc;
	asm volatile("mov %0 ,pc" : "=r"(tmp_pc));
	puthex(tmp_pc);
}

void hello_world() {
	uart_spin_puts("Hello, world!\r\n");
}
