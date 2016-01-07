.global vector_table

vector_table:
	nop // not used
	nop // undefined
	b SVC_handler
	b perfetch_abort_handler
	b data_abort_handler
	NOP
	b IRQ_handler
	NOP // FIQ

SVC_handler:
	stmfd sp!, {r0-r12, lr}
	ldr r0, [lr, #-4]
	bic r0, r0, #0xFF000000
	mov r1, sp
	bl C_SVC_handler
	ldmfd sp!, {r0-r12, pc}^

perfetch_abort_handler:
	stmfd sp!, {r0-r12, lr}
	bl C_prefetch_abort_handler
	ldmfd sp!, {r0-r12, pc}^

data_abort_handler:
	stmfd sp!, {r0-r12, lr}
	bl C_data_abort_handler
	ldmfd sp!, {r0-r12, pc}^

IRQ_handler:
	stmfd sp!, {r0-r12, lr}
	bl C_IRQ_handler
	ldmfd sp!, {r0-r12, pc}^



