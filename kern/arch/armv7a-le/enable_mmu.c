void enable_mmu() {
	asm volatile ("mcr p15, 0, r0, c2, c0, 0\r\n"
				  "psb\r\n"
				  "b 0x7FFFFFFF");
}
