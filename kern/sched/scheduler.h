#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

#include "process.h"

#define NULL 0

pcb_t* next_pcb();

pcb_t* get_current_pcb();

void scheduler_init();
void add_pcb(pcb_t* pcb);
void delete_pcb(pcb_t* pcb);

#endif