#ifndef _ELF_LOADER_H_
#define _ELF_LOADER_H_

#include <drivers/sd/sd-zynq7000.h>
#include <vm/user_page.h>
#include <vm/page_defines.h>

unsigned load_elf(unsigned program_num, pte_t *pte) {
	u32 program_start;
	if (program_num == 0) 
		program_start = 0;
	else 
		program_start = 0; 

	volatile u8 *header_start = (u8*)alloc_pages(1);
	sd_dma_spin_read((u32)header_start, 2, program_start);

	unsigned target_entry = (*(u32*)(header_start + 0x18));
	u16 program_header_size = *(u16*)(header_start + 0x2A);
	u16 program_header_count = *(u16*)(header_start + 0x2C);

	u32 program_header = *(u32*)(header_start + 0x1C);
	program_header += (u32)header_start;
	for (int i = 0; i < program_header_count; i++) {
		u32 p_offset = *(u32*)(program_header + 4);
		u32 p_paddr = *(u32*)(program_header + 12);
		u32 p_filesz = *(u32*)(program_header + 16);
		u16 p_count = (u16) (((p_paddr + p_filesz) >> 9) - (p_paddr >> 9) + 1);
		p_offset = p_offset >> 9;
		p_paddr = p_paddr >> 9 << 9;

		user_page_alloc(pte, p_paddr, (p_count + 1) / 2);

		sd_dma_spin_read((u32)p_paddr, p_count, program_start + p_offset);
		program_header = program_header + (program_header_size >> 2);
	}

	return target_entry;
}

#endif