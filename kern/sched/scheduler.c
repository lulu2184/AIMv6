#include "scheduler.h"
#include <vm/slab_defines.h>
#include <drivers/serial/uart.h>

#define NULL 0
#define PCB_LIST_T_SIZE 8

typedef struct pcb_list_s{
	pcb_t* pcb;
	struct pcb_list_s* next;
}pcb_list_t;

pcb_list_t* pcb_list_head;
pcb_list_t* pcb_list_tail;
pcb_list_t* current_pcb;

void scheduler_init() {
	pcb_list_head = NULL;
	pcb_list_tail = NULL;
	current_pcb = NULL;
	setup_idle_process();
}

void add_pcb(pcb_t* pcb) {
	uart_spin_puts("add pcb at address ");
	puthex(pcb);
	pcb_list_t* list_element = (pcb_list_t*)obj_alloc(PCB_LIST_T_SIZE);
	list_element->pcb = pcb;
	list_element->next = NULL;
	if (pcb_list_head == NULL) {
		pcb_list_head = list_element;
	}
	if (pcb_list_tail != NULL) {
		pcb_list_tail->next = list_element;
	}
	if (current_pcb == NULL) {
		current_pcb = list_element;
	}
	pcb_list_tail = list_element;
	uart_spin_puts("finish adding pcb\r\n");
}

void delete_pcb(pcb_t* pcb) {
	pcb_list_t* last_element;
	for (pcb_list_t* list_element = pcb_list_head; list_element != NULL; list_element = list_element->next) {
		if (list_element->pcb == pcb) {
			if (last_element != NULL) {
				last_element->next = list_element->next;
			}
			if (list_element == pcb_list_head) {
				pcb_list_head = list_element->next;
			}
		}
		last_element = list_element;
	}
}

pcb_t* next_pcb() {
	current_pcb = current_pcb->next;
	if (current_pcb == NULL) {
		current_pcb = pcb_list_head;
	}
	return current_pcb->pcb;
}

pcb_t* get_current_pcb() {
	return current_pcb->pcb;
}