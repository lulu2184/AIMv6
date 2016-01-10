#ifndef _SLAB_DEFINES_H_
#define _SLAB_DEFINES_H_

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
	int max_obj_size;
	int free_slabs;
	int obj_inuse;
	struct slab_pool_s* next;

	slab_t* slab_header;
}slab_pool_t;

void slab_pools_init();
void obj_free(unsigned addr, int obj_size);
void* obj_alloc(int obj_size);
int get_objinuse(int obj_size); 

#endif