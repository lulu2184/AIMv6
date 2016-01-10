#include "scheduler.h"
#include "process.h"

typedef struct pcb_list_s{
	pcb_t* pcb;
	pcb_list_t* next;
}pcb_list_t;

pcb_list* pcb_list_head;
pcb_list* pcb_list_tail;
pcb_list* current_pcb;

void scheduler_init() {
}