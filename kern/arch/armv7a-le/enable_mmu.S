.global enable_mmu

enable_mmu:
	movt r0, 0x1FF0
	lsls r0, r0, #0x10
	mcr p15, 0, r0, c2, c0, 0
	mcr p15, 0, r0, c2, c0, 1
	mrc p15, 0, r0, c1, c0, 0
	orrs r0, #0x1
	mcr p15, 0, r0, c1, c0, 0
	nop
	nop
	nop
	b 0x7FFFFFFF
	nop
	nop
	nop
