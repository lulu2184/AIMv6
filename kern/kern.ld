SECTIONS
{
    . = 0xF00000;
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
