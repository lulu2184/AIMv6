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
	struct slab_pool_s* next;

	slab_t* slab_header;
	slab_t* slab_tail;
}slab_pool_t;

const int SLAB_SIZE_NUM = 6;
const int slab_size_list[SLAB_SIZE_NUM] = {8, 16, 64, 128, 512, 1024};

void slab_pools_init();
void obj_free();
void* obj_alloc();

#endif