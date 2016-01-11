#include "mutex.h"

spinlock_t* init_lock() {
	spinlock_t* lock = (spinlock_t*)obj_alloc(sizeof(spinlock_t));
	lock->locked = 0;
	return lock;
}

void acquire(spinlock_t* lock) {
	
}

void release(spinlock_t* lock) {
}