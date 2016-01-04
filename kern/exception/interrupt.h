#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_

void interrupt_init();
void C_SVC_handler(unsigned number, unsigned *reg);
void C_prefetch_abort_handler();
void C_data_abort_handler();
void C_IRQ_handler();
void print_spsr();

void system_call(unsigned number);

void enter_user_mode();

#endif _INTERRUPT_H_