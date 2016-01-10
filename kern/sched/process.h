#ifndef _PROCESS_H_
#define _PROCESS_H_

#define PCB_SIZE 12

typedef struct pcb_s {
	unsigned pid;
	unsigned page_table_addr;
	unsigned kern_SP;
}pcb_t;

unsigned init_process(unsigned program_num);
void destroy_process(unsigned program_num);
void setup_idle_process();

#endif