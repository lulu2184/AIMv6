SECTIONS
{
    . = 0x100000;
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
