SECTIONS
{
    . = 0x400000;
	.data : {
		*(.data)
	}
	.text : {
		*(.text)
	}
	.bss : {
		*(.bss)
	}
}
ENTRY(main)
