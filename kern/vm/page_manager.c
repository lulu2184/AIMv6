#include "page_defines.h"
#include <drivers/serial/uart.h>

#define KMEM_BASE 0x1F200000

typedef struct mblock_s{
	struct mblock_s *next;
	int size;
	char *addr;
}mblock_t;

struct {
	mblock_t *freelist;
}kmem;

void alloc_init() {
	kmem.freelist = (void *)KERN_BASE;
	kmem.freelist->addr = (void *)KERN_BASE + PY_SAFE_BEGIN;
	kmem.freelist->next = NULL;
	kmem.freelist->size = (PY_SAFE_END - PY_SAFE_BEGIN) >> PAGE_SHIFT;
	puthex(kmem.freelist->size);

	uart_spin_puts("alloc init finish\r\n");
}

/**
  * alloc pnum pages for caller
  * @param pnum the number of pages 
  * if fail to alloc return 0, else return the base address of the pages
 **/
char* alloc_pages(int pnum) {
	uart_spin_puts("alloc pages\r\n");
	mblock_t *block = kmem.freelist;
	mblock_t *last = NULL;	
	char *ret = NULL;
	puthex(kmem.freelist->size);
	while (block != NULL) {
		if (block->size > pnum) {
			ret = block->addr + (block->size - pnum) * PAGE_SIZE;
			block->size -= pnum;
			break;
		}
		if (block->size == pnum) {
			ret = block->addr;
			if (last != NULL)
				last->next = block->next;
			break;
		}
		last = block;
		block = block->next;
	}
	puthex(kmem.freelist->size);
	return ret;
}

/**
  * alloc pnum pages for caller and the start address of pages should be aligned
  * @param pnum the number of pages 
  * @param aligned_shift indicates that the allocated pages should aligned to 2^(sligned_shift) (by pages) 
  * if fail to alloc return 0, else return the base address of the pages
 **/
char* alloc_aligned_pages(int pnum, int aligned_shift) {
	void *addr = alloc_pages(pnum + (1 << aligned_shift) - 1);
	void *alloc_end = (void*)((unsigned)addr >> PAGE_SHIFT + (pnum + (1 << aligned_shift) - 1));
	while (1) {
		int page_code = (unsigned)addr >> PAGE_SHIFT;
		if ((page_code & ((1 << aligned_shift) - 1)) == 0) {
			void* end = (unsigned)addr + pnum  << PAGE_SHIFT;
			free_pages(end, alloc_end - end);
			return (char*)addr;
		}
		free_pages(addr, 1);
		addr += PAGE_SIZE;
	}
}

/**
  * free size pages begin on addr 
  * @param addr the begin address of the free pages
  * @param size the number of pages to free
  * TODO: print error mesg if the pages to be freed is not allocated.
 **/
void free_pages(char *addr, unsigned size) {
	if (size == 0) return;
	if (((unsigned)addr & (PAGE_SIZE - 1)) > 0) {
		uart_spin_puts("free page base address is not aligned.\r\n");
		return;
	}

	uart_spin_puts("free pages\r\n");
	mblock_t *block = kmem.freelist;
	puthex(kmem.freelist->size);
	mblock_t *last = NULL;
	while (block != NULL) {
		if ((unsigned)block->addr > (unsigned)addr) {
			puthex((unsigned)block->addr);
			puthex((unsigned)addr);
			if (last != NULL && last->addr + (last->size << PAGE_SHIFT) == addr) {
				last->size += size;
			} else {
				mblock_t *new_block = (mblock_t*)addr;
				new_block->next = block;
				new_block->size = size;
				new_block->addr = addr;
				if (last != NULL) 
					last->next = new_block;
				else 
					kmem.freelist = new_block;
				last = new_block;
			}
			if (last->addr + (last->size << PAGE_SHIFT) == block->addr) {
				last->next = block ->next;
				last->size = last->size + block->size;
			}
			puthex(kmem.freelist->size);
			uart_spin_puts("free finish.\r\n");	
			return;
		}
		last = block;
		block = block->next;
	}
	if (last != NULL && last->addr + (last->size << PAGE_SHIFT) == addr) {
		last->size += size;
	} else {
		mblock_t *new_block = (mblock_t*)addr;
		new_block->next = NULL;
		new_block->size = size;
		new_block->addr = addr;
		if (last != NULL) 
			last->next = new_block;
		else 
			kmem.freelist = new_block;
	}	
	puthex(kmem.freelist->size);
	uart_spin_puts("free finish.\r\n");	
	return;
}