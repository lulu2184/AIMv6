#include "vm/page_defines.h"
#include "kernel.h"
#include "puthex.h"
#include <drivers/serial/uart.h>

void test_fail() {
	uart_spin_puts("FAIL\r\n");
	while (1);
}

void pages_manager_test() {
	uart_spin_puts("PAGES MANAGER TEST: ");
	char* addr = alloc_pages(2);
	if ((unsigned)addr != 0x9EFE0000) test_fail();
	free_pages(addr, 1);
	unsigned first_size = get_kmem_first_size();
	if (first_size != 0x1E0F) test_fail();
	addr = alloc_pages(2);
	first_size = get_kmem_first_size();
	if (first_size != 0x1E0D) test_fail();
	if ((unsigned)addr != 0x9EFD0000) test_fail();
	free_pages(addr + PAGE_SIZE, 1);
	first_size = get_kmem_first_size();
	if (first_size != 0x1E0D) test_fail();
	free_pages(addr, 1);
	first_size = get_kmem_first_size();
	if (first_size != 0x1E0F) test_fail();
	uart_spin_puts("PAGES MANAGER TEST: ");
	uart_spin_puts("PASS\r\n");
}

int kernel_entry() {
	uart_spin_puts("Hello kernel!\r\n");
	init_first_page_table();
	unsigned tmp;
	asm volatile(
		"ldr fp, =0x80F00000\r\n"
		"mov sp, fp"
	);
	remove_low_mapping();
	// asm volatile("mov %0, sp" : "=r"(tmp));
	// puthex(tmp);
	uart_spin_puts("Kernel space!: PC = ");
	asm volatile("mov %0 ,pc" : "=r"(tmp));
	puthex(tmp);
	// TODO!! if delete the two lines below, the following codes will not be executed.
	asm volatile("mov %0 ,pc" : "=r"(tmp));
	puthex(tmp);
	alloc_init();
	pages_manager_test();

	asm volatile("mov %0 ,sp" : "=r"(tmp));
	puthex(tmp);

	while (1);
}
