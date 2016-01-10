#ifndef _MEMCPY_H_
#define _MEMCPY_H_

static inline void memcpy(char *dst, char *src, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		*dst = *src;
		dst++;
		src++;
	}
}

#endif