#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

#include "process.h"

void scheduler_init();
void add_pcb(pcb_t* pcb);
void delete_pcb(pcb_t* pcb);
pcb_t* next_pcb();
pcb_t* get_current_pcb();

#endif