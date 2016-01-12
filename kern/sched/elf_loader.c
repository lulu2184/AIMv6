#include "elf_loader.h"
#include <drivers/sd/sd-zynq7000.h>
#include <vm/user_page.h>
#include "arch/armv7a-le/asm/irq.h"
#include "puthex.h"

unsigned load_elf(unsigned program_num, pte_t *pte) {
	uart_spin_puts("read elf\r\n");
	// u32 program_start;
	// if (program_num == 0) 
	// 	program_start = 0;
	// else 
	// 	partition = 0xA0000000; 

	volatile u8 *mbr = (void *)((unsigned)alloc_pages(1) - 0x80000000 + 2);
	sd_dma_spin_read((u32)mbr, 1, 0);
	mbr += 0x80000000;
	u32 partition_start = *(u32*)(mbr + 0x1E6);


	volatile u8* header_start = (u8*)((unsigned)alloc_pages(1) - 0x80000000);
	puthex((unsigned)header_start);
	puthex((unsigned)partition_start);
	sd_dma_spin_read((u32)header_start, 1, partition_start);
	uart_spin_puts("read first block finish\r\n");

	header_start += 0x80000000;
	puthex((u32)header_start);
	puthex(*(u32*)(header_start));
	unsigned target_entry = (*(u32*)(header_start + 0x18));
	u16 program_header_size = *(u16*)(header_start + 0x2A);
	u16 program_header_count = *(u16*)(header_start + 0x2C);

	puthex(target_entry);
	puthex(program_header_size);
	puthex(program_header_count);

	u32 program_header = *(u32*)(header_start + 0x1C);
	program_header += (u32)header_start;
	puthex(program_header);
	for (int i = 0; i < program_header_count; i++) {
		puthex(i);
		u32 p_offset = *(u32*)(program_header + 4);
		u32 p_paddr = *(u32*)(program_header + 12);
		u32 p_filesz = *(u32*)(program_header + 16);
		u16 p_count = (u16) (((p_paddr + p_filesz) >> 9) - (p_paddr >> 9) + 1);
		p_offset = p_offset >> 9;
		p_paddr = p_paddr >> 9 << 9;

		unsigned paddr = user_page_alloc(pte, p_paddr, (p_count >> 3) + 1);
		uart_spin_puts("wawaw\r\n");

		sd_dma_spin_read((u32)paddr, p_count, partition_start + p_offset);
		paddr += 0x80000000 + 0x98;
		puthex(paddr);
		puthex(*(unsigned*)(paddr));
		program_header = program_header + (program_header_size >> 2);
	}

	uart_spin_puts("finish read elf\r\n");
	return target_entry;
}