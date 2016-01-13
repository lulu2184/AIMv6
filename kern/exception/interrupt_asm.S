.global vector_table

.global SVC_handler
.global prefetch_abort_handler
.global data_abort_handler
.global IRQ_handler

.text
.arm

.align 8

vector_table:
	nop // not used
	nop // undefined
	b SVC_handler
	b prefetch_abort_handler
	b data_abort_handler
	NOP
	b IRQ_handler
	NOP // FIQ

SVC_handler:
	stmfd sp!, {r0-r12, lr}
	mrs r0, spsr
	stmfd sp!, {r0, r3}
	ldr r0, [lr, #-4]
	bic r0, r0, #0xFF000000
	mov r1, sp
	add r1, r1, #8
	mov r2, lr
	bl C_SVC_handler
	ldmfd sp!, {r0, r3}
	msr spsr_cxsf, r0
	ldmfd sp!, {r0-r12, pc}^

prefetch_abort_handler:
	stmfd sp!, {r0-r12, lr}
	mov r0, lr
	bl C_prefetch_abort_handler
	ldmfd sp!, {r0-r12, pc}^

data_abort_handler:
	stmfd sp!, {r0-r12, lr}
	mov r0, lr
	bl C_data_abort_handler
	stmfd sp!, {r0}
	ldmfd sp!, {r0-r12, lr}
	ldmfd sp!, {pc}^

IRQ_handler:
	sub lr, lr, #4
	stmfd sp!, {r0-r12, lr}
	mrs r0, spsr
	stmfd sp!, {r0, r3}
	mov r0, lr
	bl C_IRQ_handler
	ldmfd sp!, {r0, r3}
	msr spsr_cxsf, r0
	ldmfd sp!, {r0-r12, pc}^



