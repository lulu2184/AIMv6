.global

enable_mmu:

mcr p15, 0, r0, c2, c0, 0
psb
b 0x7FFFFFFF
