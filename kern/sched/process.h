#ifndef _PROCESS_H_
#define _PROCESS_H_

typedef struct pcb_s {
	unsigned pid;
	unsigned page_table_addr;
}pcb_t;

#endif