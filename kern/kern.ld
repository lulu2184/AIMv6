SECTIONS
{
    . = 0x700000;
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
ENTRY(kernel_entry)
