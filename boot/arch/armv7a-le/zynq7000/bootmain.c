#define PRELOAD_VECTOR_BASE 0x1ff00000

#include "sys/types.h"
void (*uart_spin_puts)(const char *) = (void *)(PRELOAD_VECTOR_BASE + 0xC);
int (*sd_dma_spin_read)(u32, u16, u32) = (void *)0x1ff00010;
void (*puthex)(u32) = (void *)0x1ff00014;

void mbr_bootmain(void) {
	uart_spin_puts("Jump into MBR\r\n");

	volatile u8 *mbr = (void *)0x200002;
	sd_dma_spin_read((u32)mbr, 1, 0);
	u32 partition2_start = *(u32*)(mbr + 0x1D6);

	/* read header of ELF from SD card to memory (address: header_start) */
	volatile u8 *header_start = (void *)0x300000;
	sd_dma_spin_read((u32)header_start, 3, partition2_start);

	puthex(partition2_start);

	void (*entry_point)(void) = (void *)(*(u32*)(header_start + 0x18));
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

		sd_dma_spin_read((u32)p_paddr, p_count, partition2_start + p_offset);
		program_header = program_header + (program_header_size >> 2);
	}

	uart_spin_puts("MBF end\r\n");
	entry_point();
}
