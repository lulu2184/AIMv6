#include "page_defines.h"

typedef struct obj_s{
	struct obj_s* next;
}obj_t;

typedef struct slab_s{
	int obj_remain;
	obj_t* free_obj_header;
	struct slab_s* next;
}slab_t;

typedef struct slab_pool_s{
	int obj_size;
	struct slab_pool_s* next;

	slab_t* slab_header;
	slab_t* slab_tail;
}slab_pool_t;

const int slab_size_list[5] = {8, 16, 64, 128, 512};
const int SLAB_SIZE_NUM = 5;

slab_pool_t* slab_pool_header;

void fail() {
	while (1);
}

void slab_init(unsigned addr, int pnum, int obj_size) {
	slab_t* slab = (slab_t*)addr;
	slab->obj_remain = 0;
	for (int j = 0; j < pnum; j++) {
		for (unsigned obj_addr = addr + obj_size; obj_addr < addr + PAGE_SIZE; obj_addr += obj_size) {
			obj_t *obj = (obj_t*)obj_addr;
			slab->obj_remain++;
			if (obj_addr + obj_size == addr + PAGE_SIZE)
				obj->next = NULL;
			else
				obj->next = (obj_t*)(obj_addr + obj_size);
		}
		if (j < pnum)
			slab->next = (slab_t*)(addr + PAGE_SIZE);
		addr += PAGE_SIZE;
		slab = slab->next;
	}
}

void slab_pools_init() {
	unsigned addr = alloc_pages(1);
	slab_pool_t* now = (slab_pool_t*)addr;
	slab_pool_t* last = NULL;
	for (int i = SLAB_SIZE_NUM - 1; i >= 0; i++) {
		now->obj_size = slab_size_list[i];
		now->next = last;
		addr = alloc_pages(4);
		now->slab_header = (slab_t*)addr;
		slab_init(addr, 4, now->obj_size);
		now->slab_tail = (slab_t*)(addr + PAGE_SIZE * 3);
		last = now;
	}
}

void* slab_alloc(int obj_size, int obj_num) {

}

void slab_free() {

}

int is_in_slab(slab_t* slab, unsigned addr, int obj_size) {
	unsigned slab_addr = (unsigned)slab;
	if (slab_addr + obj_size <= addr && slab_addr + PAGE_SIZE >= addr) return 1;
	return 0;
}

void obj_free(unsigned addr, int obj_size) {
	for (slab_pool_t *slab_pool = slab_pool_header; slab_pool != NULL; slab_pool = slab_pool->next) {
		if (slab_pool->obj_size > obj_size) {
			if ((addr & (slab_pool->obj_size - 1)) > 0) {
				uart_spin_puts("The address of object to be freed is not aligned\r\n");
				fail();
			}
			for (slab_t* slab = slab_pool->slab_header; slab != NULL; slab = slab->next) {
				if (is_in_slab(slab, addr, slab_pool->obj_size)) {
					obj_t* obj = (obj_t*)addr;
					obj->next = slab->free_obj_header;
					slab->free_obj_header = obj;
					return;
				}
			}
		}
	}
	uart_spin_puts("fail to free object for slab\r\n");
	fail();
}

void* obj_alloc(int obj_size) {
	for (slab_pool_t* slab_pool = slab_pool_header; slab_pool != NULL; slab_pool = slab_pool->next) {
		if (slab_pool->obj_size > obj_size) {
			for (slab_t* slab = slab_pool->slab_header; ; slab = slab->next) {
				if (slab == NULL) {
					slab = (slab_t*)alloc_pages(1);
					slab_pool->slab_tail->next = slab;
					slab_pool->slab_tail = slab;
					slab_init((unsigned)slab, 1, slab_pool->obj_size);
				}
				if (slab->obj_remain > 0) {
					obj_t *obj = (obj_t*)slab->free_obj_header;
					slab->free_obj_header = obj->next;
					slab->obj_remain--;
					return (void*)obj;
				}
			}
		}
	}
	uart_spin_puts("fail to alloc object for slab\r\n");
	fail();
}
