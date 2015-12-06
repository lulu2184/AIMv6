#include "page_defines.h"
#include "slab_defines.h"

const int SLAB_SIZE_NUM = 6;
const int slab_size_list[6] = {8, 16, 64, 128, 512, 1024};

slab_pool_t* slab_pool_header;

int slab_alloc(slab_pool_t *slab_pool, int slab_num);

void fail() {
	while (1);
}

/**
 *  Initialize multiple slabs.
 *  @param addr: base address of slabs
 *  @param pnum: the number of slabs(in continuous pages)
 *  @param obj_size: the size of the object in slabs(in bytes)
 **/
void slab_init(unsigned addr, int pnum, int obj_size) {
	slab_t* slab = (slab_t*)addr;
	slab->obj_remain = 0;
	for (int j = 0; j < pnum; j++) {
		slab->free_obj_header = (obj_t*)(addr + obj_size);
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

/**
 *  Initialize slab pools. There are multiple pools one for each object size.
 *	Each pool has multiple slabs. At the beginning, each pools have 4 empty slabs.
 **/
void slab_pools_init() {
	unsigned addr = (unsigned)alloc_pages(1);
	if (addr == 0) {
		uart_spin_puts("Fail to initialize slab pools.\r\n");
		fail();
	}
	slab_pool_t* last = NULL;
	for (int i = SLAB_SIZE_NUM - 1; i >= 0; i--) {
		slab_pool_t* now = (slab_pool_t*)addr + sizeof(slab_pool_t) * i;
		now->obj_size = slab_size_list[i];
		now->obj_inuse = 0;
		now->next = last;
		slab_alloc(now, 4);
		last = now;
	}
	slab_pool_header = last;
	uart_spin_puts("slabs init finish\r\n");
}

/**
 *  Alloc new slabs.
 *	@param slab_pool: pointer of the slab pool which the new allocated slab in
 *  @param slab_num: indicate the number of slabs should be allocated at this time
 *	@return if success return 0, otherwise return -1
 **/
int slab_alloc(slab_pool_t *slab_pool, int slab_num) {
	char* addr_ptr = alloc_pages(4);
	if (addr_ptr == NULL) {
		uart_spin_puts("Fail to alloc slab. Free space not enough.\r\n");
		return -1;
	}
	unsigned addr = (unsigned)addr_ptr;
	slab_pool->slab_header = (slab_t*)addr;
	slab_init(addr, 4, slab_pool->obj_size);
	slab_pool->max_obj_size = slab_pool->slab_header->obj_remain;
	return 0;
}

void slab_free(slab_t *slab, slab_pool_t *slab_pool, slab_t *last_slab) {
	if (slab_pool->slab_header == slab) {
		slab_pool->slab_header = slab->next;
	} else {
		last_slab->next = slab->next;
	}
	free_pages((char*)slab, 1);
}

int is_in_slab(slab_t* slab, unsigned addr, int obj_size) {
	unsigned slab_addr = (unsigned)slab;
	if (slab_addr + obj_size <= addr && slab_addr + PAGE_SIZE >= addr) return 1;
	return 0;
}

void obj_free(unsigned addr, int obj_size) {
	uart_spin_puts("object allocation.\r\n object size = ");
	puthex(obj_size);
	uart_spin_puts("addr = ");
	puthex(addr);
	for (slab_pool_t *slab_pool = slab_pool_header; slab_pool != NULL; slab_pool = slab_pool->next) {
		if (slab_pool->obj_size > obj_size) {
			if ((addr & (slab_pool->obj_size - 1)) > 0) {
				uart_spin_puts("The address of object to be freed is not aligned\r\n");
				fail();
			}
			slab_pool->obj_inuse--;
			slab_t *last_slab = NULL;
			for (slab_t* slab = slab_pool->slab_header; slab != NULL; slab = slab->next) {
				if (is_in_slab(slab, addr, slab_pool->obj_size)) {
					obj_t* obj = (obj_t*)addr;
					obj->next = slab->free_obj_header;
					slab->free_obj_header = obj;
					if (slab->obj_remain == slab_pool->max_obj_size) {
						slab_pool->free_slabs++;
						if (slab_pool->free_slabs > 4)
							slab_free(slab, slab_pool, last_slab);
					}
					return;
				}
				last_slab = slab;
			}
		}
	}
	uart_spin_puts("fail to free object for slab\r\n");
	fail();
}

void* obj_alloc(int obj_size) {
	uart_spin_puts("object allocation.\r\nobject size = ");
	puthex(obj_size);
	if (obj_size > slab_size_list[SLAB_SIZE_NUM - 1]) {
		uart_spin_puts("Try to alloc too large object. Use page allocation instead.\r\n");
		return NULL;
	}
	for (slab_pool_t* slab_pool = slab_pool_header; slab_pool != NULL; slab_pool = slab_pool->next) {
		if (slab_pool->obj_size > obj_size) {
			for (slab_t* slab = slab_pool->slab_header; ; slab = slab->next) {
				puthex(slab->obj_remain);
				if (slab == NULL) {
					slab = (slab_t*)alloc_pages(1);
					if (slab == NULL) {
						uart_spin_puts("No free space to alloc object.\r\n");
						return NULL;
					} else { 
						slab->next = slab_pool->slab_header;
						slab_pool->slab_header = slab;
						slab_init((unsigned)slab, 1, slab_pool->obj_size);
					}
				}
				if (slab->obj_remain > 0) {
					slab_pool->obj_inuse++;
					puthex(slab_pool->obj_inuse);
					obj_t *obj = (obj_t*)slab->free_obj_header;
					slab->free_obj_header = obj->next;
					if (slab->obj_remain == slab_pool->max_obj_size)
						slab_pool->free_slabs--;
					slab->obj_remain--;
					uart_spin_puts("object allocation finish.\r\n");
					return (void*)obj;
				}
			}
		}
	}
	uart_spin_puts("fail to alloc object for slab\r\n");
	fail();
}

int get_objinuse(int obj_size) {
	if (obj_size > slab_size_list[SLAB_SIZE_NUM - 1]) return -1;
	for (slab_pool_t* slab_pool = slab_pool_header; slab_pool != NULL; slab_pool = slab_pool->next) {
		if (slab_pool->obj_size >= obj_size) return slab_pool->obj_inuse;
	}		
}
