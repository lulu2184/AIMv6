ENTRY(mbr_bootmain)

MEMORY
{
	MBR (rwx) :
		ORIGIN = 0x100000,
		LENGTH = 446
}

SECTIONS
{
	.text : {
		*(.text .rodata)
	}
	.data : {
		*(.data)
	}
	.bss : {
		*(.bss)
	}
}
