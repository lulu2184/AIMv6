#ifndef _USER_PAGE_H_
#define _USER_PAGE_H_

void setup_page_table();
void remove_page_table();
void user_page_alloc(unsigned addr, int pnum);
void user_page_free(unsigned add, int pnum);

#endif