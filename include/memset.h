#ifndef _MEMSET_H_
#define _MEMSET_H_

#include "sys/types.h"

static inline void memset(char *dst, u8 val, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		*dst = val;
		dst++;
	}
}

#endif