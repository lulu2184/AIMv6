#include "page_defines.h"
#include <drivers/serial/uart.h>

#define KMEM_BASE 0x1F200000
#define NULL 0

typedef struct mblock_s{
	struct mblock_s *next;
	int size;
	char *addr;
}mblock_t;

struct {
	mblock_t *freelist;
}kmem;

void alloc_init() {
	kmem.freelist = (void *)KMEM_BASE;
	kmem.freelist -> next = NULL;
	kmem.freelist -> size = (PY_SAFE_END - PY_SAFE_BEGIN) >> PAGE_SHIFT;

	uart_spin_puts("alloc init finish\r\n");
}

/**
  * alloc pnum pages for caller
  * @param pnum the number of pages 
  * if fail to alloc return -1, else return the base address of the pages
 **/
char* alloc_pages(int pnum) {
	mblock_t *block = kmem.freelist;
	mblock_t *last = NULL;	
	char *ret = NULL;
	while (block != NULL) {
		if (block -> size > pnum) {
			ret = block -> addr;
			block -> size -= pnum;
			break;
		}
		if (block -> size == pnum) {
			ret = block -> addr;
			if (last != NULL)
				last -> next = block -> next;
			break;
		}
		last = block;
		block = block -> next;
	}
	return ret;
}

/**
  * free size pages begin on addr 
  * @param addr the begin address of the free pages
  * @param size the number of pages to free
 **/
void free_pages(char *addr, unsigned size) {
	addr += KERN_BASE;
	mblock_t *block = kmem.freelist;
	mblock_t *last = NULL;
	while (block != NULL) {
		if (block -> addr > addr) {
			if (block -> addr + PAGE_SIZE == addr) {
				block -> addr = addr;
				block -> size += size;
			} else {
				mblock_t *new_block = (mblock_t*)addr;
				new_block -> next = block;
				new_block -> size = size;
				new_block -> addr = addr;
				if (last != NULL) 
					last -> next = new_block;
				else 
					kmem.freelist = new_block;
				block = new_block;
			}

			if (last != NULL && last -> addr + (last -> size << PAGE_SHIFT) == block -> addr) {
				last -> next = block -> next;
				last -> size = last -> size + block -> size;
			}
			return;
		}
		last = block;
		block = block -> next;
	}
}