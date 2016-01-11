#ifndef _USER_PAGE_H_
#define _USER_PAGE_H_

#include "page_defines.h"

pte_t* setup_page_table();
void remove_page_table(pte_t *pte);
unsigned user_page_alloc(pte_t *pte, unsigned addr, int pnum);
void user_page_free(pte_t *pte, unsigned add, int pnum);

#endif