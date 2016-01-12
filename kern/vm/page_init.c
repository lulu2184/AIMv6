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
	for (char *addr = 0; addr < (char *)PYMEM_SIZE; addr += MEM_SECTION_SIZE) {
		pme = page_table + ((unsigned)addr >> MEM_SECTION_SHIFT);
		fill_pme_common(pme);
		pme->B = 0;			
		pme->C = 0;			
		pme->AP_L = 0x1;	//Privileged access only AP: 001
		pme->TEX = 0x0; 	
		pme->AP_H = 0x0; 	//Privileged access only
		pme->S = 0x1;		//sharable
		pme->ng = 0;		//global
		pme->base = (unsigned)addr >> MEM_SECTION_SHIFT;
	}

	/* mapping for preserved and non-preserved address PA <=> VA + KERN_BASE*/
	page_table = (pme_t *)PRESERVED_MEM_BASE + (KERN_BASE >> MEM_SECTION_SHIFT);
	for (char* addr = 0; addr < (char *)PYMEM_SIZE; addr += MEM_SECTION_SIZE) {
		pme = page_table + ((unsigned)addr >> MEM_SECTION_SHIFT);
		fill_pme_common(pme);
		pme->B = 0;			
		pme->C = 0;			
		pme->AP_L = 0x1;	//Privileged access only AP: 001
		pme->TEX = 0x0; 	
		pme->AP_H = 0x0; 	//Privileged access only
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
	for (unsigned addr = EXTMEM_BASE >> MEM_SECTION_SHIFT; addr < (0xFFFFFFFF >> MEM_SECTION_SHIFT); addr++) {
		pme_t *pme = page_table + addr;
		fill_pme_common(pme);
		pme->B = 0;			//device
		pme->C = 0;			//device
		pme->AP_L = 0x1;	//Privileged access only AP: 001
		pme->TEX = 0; 		//device
		pme->AP_H = 0x0;	//Privileged access only
		pme->S = 0x1;		//sharable
		pme->ng = 0;		//Non-global
		pme->base = addr;
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

static inline void enable_mmu() {
	asm volatile(
		"ldr r0, =0x1F000000\r\n"
		"mcr p15, 0, r0, c2, c0, 0\r\n"
		"mov r0, #0\r\n"
 		"mcr p15, 0, r0, c8, c7, 0\r\n"
 		"mov r0, #0x3\r\n"
 		"mcr p15, 0, r0, c3, c0, 0\r\n"
 		"isb\r\n"
		"mrc p15, 0, r0, c1, c0, 0\r\n"
		"orr r0, r0, #0x1\r\n"
		"mcr p15, 0, r0, c1, c0, 0\r\n"
		"isb");	
}

/**
 * Initialize mapping from virtual memory to physical memory
 * for the kernel.
 **/
void init_first_page_table() {
	asm volatile(
		"ldr r1, [sp, #0]\r\n"
		"ldr r0, =0x80000000\r\n"
		"add r0, r1, r0\r\n"
		"str r0, [sp, #0]\r\n"
	);
	uart_spin_puts("init first page table\r\n");
	init_mapping();
	devices_mapping();
	enable_mmu();
	uart_spin_puts("enabled MMU\r\n");
}		
