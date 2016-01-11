#ifndef _ELF_LOADER_H_
#define _ELF_LOADER_H_

#include <vm/page_defines.h>

unsigned load_elf(unsigned program_num, pte_t *pte);

#endif