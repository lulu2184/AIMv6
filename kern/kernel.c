#include "vm/page_defines.h"
#include "kernel.h"

/**
 * entry point of kernel
**/
int kernel_entry() {
	init_first_page_table();
}