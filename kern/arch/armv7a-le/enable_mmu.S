.global enable_mmu

enable_mmu:
	mov r0, #0x1F00
	lsl r0, r0, #0x10
	mcr p15, 0, r0, c2, c0, 0
	mov r0, #0
 	mcr p15, 0, r0, c8, c7, 0
 	ldr r0, =0x55555555
 	mcr p15, 0, r0, c3, c0, 0
	mrc p15, 0, r0, c1, c0, 0
	orr r0, r0, #0x1
	mcr p15, 0, r0, c1, c0, 0
	nop
	nop
	nop
	nop
	ldr r0, =0x80000000
	add r14, r0
	mov r15, r14
	nop
	nop
	nop
	nop