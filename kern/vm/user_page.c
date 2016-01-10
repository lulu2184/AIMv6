#include "page_defines.h"
#include <memset.h>
#include <memcpy.h>
#include <panic.h>
#include <vm/slab_defines.h>

pte_t* setup_page_table() {
	char* entry = alloc_aligned_pages(4, 2);
	memset(entry, 0, PAGE_SIZE << 1);
	char* kt_entry = (void *)(PRESERVED_MEM_BASE + (PAGE_SIZE << 1));
	memcpy(entry, kt_entry, PAGE_SIZE << 1);
	return (pte_t*)entry;
}

void remove_L2_page_table(unsigned base_addr) {
	memset((char*)base_addr, 0, L2_PDE_ENTRIES * 4);
	obj_free(base_addr, L2_PDE_ENTRIES * 4);
}

void remove_page_table(pte_t *pte) {
	for (unsigned i = 0; i < L1_PTE_ENTRIES; i++) {
		if (pte->type == 0x1) {
			remove_L2_page_table(pte->pte_base << 10);
		}
		pte->type = 0;
		pte++;
	}
	free_pages((char*)pte, 4);
}

void user_page_alloc(pte_t *pte, unsigned addr, int pnum) {
	unsigned phyaddr = (unsigned)alloc_pages(pnum) + 0x80000000;
	pte = pte + (addr >> MEM_SECTION_SHIFT);
	pde_t* pde;
	if (pte->type == 0) {
		pte->type = 1;
		pde = obj_alloc(1024);
		pte->pte_base = (unsigned)pde >> 10;
		memset((char*)pde, 0, 1024);
	}
	pde = (pde_t*)(pte->pte_base << 10);
	unsigned L2_offset = (addr >> 12) & 0xFFF;
	pde = pde + L2_offset;
	for (int i = 0; i < pnum; i++) {
		if (pde->type == 0) {
			pde->type = 1;
			pde->memattr = 0;		
			pde->AP = 0x3;	//Full Access AP: 001
			pde->TEX = 0x0; 	
			pde->APX = 0x0; 	//Full Access
			pde->S = 0x0;		
			pde->ng = 0;		
			pde->base = (unsigned)phyaddr >> PAGE_SHIFT;
		} else {
			panic("page has been used.\r\n");
		}
		pde++;
	}
}

void user_page_free(pte_t* pte, unsigned addr, int pnum) {
	pte = pte + (addr >> MEM_SECTION_SHIFT);
	pde_t* pde = (pde_t*)(pte->pte_base << 10);
	unsigned L2_offset = (addr >> 12) & 0xFFF;
	pde = pde + L2_offset;
	for (int i = 0; i < pnum; i++) {
		pde->type = 0;
		pde++;
	}
}

