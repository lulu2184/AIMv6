#include "vm/page_defines.h"
#include "vm/slab_defines.h"
#include "kernel.h"
#include "puthex.h"
#include <drivers/serial/uart.h>

void test_fail(const char *str) {
	uart_spin_puts(str);
	uart_spin_puts("FAIL\r\n");
	while (1);
}

void pages_manager_test() {
	char *test_name = "PAGES MANAGER TEST: ";
	uart_spin_puts("PAGES MANAGER TEST: \r\n");
	char* addr = alloc_pages(2);
	puthex((unsigned)addr);
	if ((unsigned)addr != 0x9EFE0000) test_fail(test_name);
	free_pages(addr, 1);
	unsigned first_size = get_kmem_first_size(test_name);
	puthex(first_size);
	if (first_size != 0x1CFF) test_fail(test_name);
	addr = alloc_pages(2);
	first_size = get_kmem_first_size(test_name);
	puthex(first_size);
	if (first_size != 0x1CFD) test_fail(test_name);
	puthex((unsigned)addr);
	if ((unsigned)addr != 0x9EFD0000) test_fail(test_name);
	free_pages(addr + PAGE_SIZE, 1);
	first_size = get_kmem_first_size(test_name);
	puthex(first_size);
	if (first_size != 0x1CFD) test_fail(test_name);
	free_pages(addr, 1);
	first_size = get_kmem_first_size(test_name);
	puthex(first_size);
	if (first_size != 0x1CFF) test_fail(test_name);
	uart_spin_puts("PAGES MANAGER TEST: ");
	uart_spin_puts("PASS\r\n");
}

void pages_manager_test_overlap() {
	uart_spin_puts("PAGES MANAGER TEST OVERLAP: \r\n");
}

void pages_manager_test_exposure() {
	uart_spin_puts("PAGES MANAGER TEST EXPOSE: \r\n");
	for (int i = 0;; i = (i + 1) % 10 + 1){
		char* addr = alloc_pages(i);
		if (addr == NULL) {
			test_fail("PAGES MANAGER TEST EXPOSE: ");
		}
		free_pages(addr, i);
	}
}

void slab_manager_test() {
	uart_spin_puts("SLABS MANAGER TEST: \r\n");
	slab_pools_init();
	unsigned addr_array[21];
	for (int i = 0; i <= 20; i++) {
		void* addr = obj_alloc(511);
		addr_array[i] = (unsigned)addr;
		int objinuse = get_objinuse(512);
		puthex(objinuse);
		if (objinuse != i + 1) {
			test_fail("SLABS MANAGER TEST: ");
		}
	}
	for (int i = 0; i <= 20; i++) {
		obj_free(addr_array[i], 511);
		int objinuse = get_objinuse(511);
		if (objinuse != 20 - i) {
			test_fail("SLABS MANAGER TEST: ");
		}
	}
	uart_spin_puts("SLABS MANAGER TEST: PASS\r\n");
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
	uart_spin_puts("Kernel space!: PC = ");
	asm volatile("mov %0 ,pc" : "=r"(tmp));
	puthex(tmp);
	alloc_init();
	pages_manager_test();
	// pages_manager_test_overlap();	
	// pages_manager_test_exposure();

	uart_spin_puts("SP = ");
	asm volatile("mov %0 ,sp" : "=r"(tmp));
	puthex(tmp);

	slab_manager_test();

	while (1);
}
