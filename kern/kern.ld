SECTIONS
{
    . = 0x200000;
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
