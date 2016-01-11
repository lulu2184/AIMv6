#ifndef _MUTEX_H_
#define _MUTEX_H_

typedef struct spinlock_s {
  uint locked;
}spinlock_t;

spinlock_t* init_lock();
void acquire(spinlock_t* lock);
void release(spinlock_t* lock);

#endif