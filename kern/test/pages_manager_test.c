#include "test.h"
#include "../vm/page_defines.h"

void pages_manager_test() {
	char* addr = alloc_pages(2);
	puthex((unsigned)addr);
	free_pages(addr, 1);
	addr = alloc_pages(2);
	puthex((unsigned)addr);
	free_pages(addr + PAGE_SIZE, 1);
	free_pages(addr, 1);
}