
kern/kern_test.elf:     file format elf32-littlearm


Disassembly of section .text:

00700018 <test_fail>:
  700018:	e92d4800 	push	{fp, lr}
  70001c:	e28db004 	add	fp, sp, #4
  700020:	e59f300c 	ldr	r3, [pc, #12]	; 700034 <test_fail+0x1c>
  700024:	e08f3003 	add	r3, pc, r3
  700028:	e1a00003 	mov	r0, r3
  70002c:	eb000481 	bl	701238 <uart_spin_puts>
  700030:	eafffffe 	b	700030 <test_fail+0x18>
  700034:	000013cc 	.word	0x000013cc

00700038 <pages_manager_test>:
  700038:	e92d4800 	push	{fp, lr}
  70003c:	e28db004 	add	fp, sp, #4
  700040:	e24dd008 	sub	sp, sp, #8
  700044:	e59f3118 	ldr	r3, [pc, #280]	; 700164 <pages_manager_test+0x12c>
  700048:	e08f3003 	add	r3, pc, r3
  70004c:	e1a00003 	mov	r0, r3
  700050:	eb000478 	bl	701238 <uart_spin_puts>
  700054:	e3a00002 	mov	r0, #2
  700058:	eb0001c1 	bl	700764 <alloc_pages>
  70005c:	e50b0008 	str	r0, [fp, #-8]
  700060:	e51b2008 	ldr	r2, [fp, #-8]
  700064:	e3a03000 	mov	r3, #0
  700068:	e3493efe 	movt	r3, #40702	; 0x9efe
  70006c:	e1520003 	cmp	r2, r3
  700070:	0a000000 	beq	700078 <pages_manager_test+0x40>
  700074:	ebffffe7 	bl	700018 <test_fail>
  700078:	e3a01001 	mov	r1, #1
  70007c:	e51b0008 	ldr	r0, [fp, #-8]
  700080:	eb00023b 	bl	700974 <free_pages>
  700084:	eb000187 	bl	7006a8 <get_kmem_first_size>
  700088:	e50b000c 	str	r0, [fp, #-12]
  70008c:	e51b300c 	ldr	r3, [fp, #-12]
  700090:	e3012e0f 	movw	r2, #7695	; 0x1e0f
  700094:	e1530002 	cmp	r3, r2
  700098:	0a000000 	beq	7000a0 <pages_manager_test+0x68>
  70009c:	ebffffdd 	bl	700018 <test_fail>
  7000a0:	e3a00002 	mov	r0, #2
  7000a4:	eb0001ae 	bl	700764 <alloc_pages>
  7000a8:	e50b0008 	str	r0, [fp, #-8]
  7000ac:	eb00017d 	bl	7006a8 <get_kmem_first_size>
  7000b0:	e50b000c 	str	r0, [fp, #-12]
  7000b4:	e51b300c 	ldr	r3, [fp, #-12]
  7000b8:	e3012e0d 	movw	r2, #7693	; 0x1e0d
  7000bc:	e1530002 	cmp	r3, r2
  7000c0:	0a000000 	beq	7000c8 <pages_manager_test+0x90>
  7000c4:	ebffffd3 	bl	700018 <test_fail>
  7000c8:	e51b2008 	ldr	r2, [fp, #-8]
  7000cc:	e3a03000 	mov	r3, #0
  7000d0:	e3493efd 	movt	r3, #40701	; 0x9efd
  7000d4:	e1520003 	cmp	r2, r3
  7000d8:	0a000000 	beq	7000e0 <pages_manager_test+0xa8>
  7000dc:	ebffffcd 	bl	700018 <test_fail>
  7000e0:	e51b3008 	ldr	r3, [fp, #-8]
  7000e4:	e2833801 	add	r3, r3, #65536	; 0x10000
  7000e8:	e3a01001 	mov	r1, #1
  7000ec:	e1a00003 	mov	r0, r3
  7000f0:	eb00021f 	bl	700974 <free_pages>
  7000f4:	eb00016b 	bl	7006a8 <get_kmem_first_size>
  7000f8:	e50b000c 	str	r0, [fp, #-12]
  7000fc:	e51b300c 	ldr	r3, [fp, #-12]
  700100:	e3012e0d 	movw	r2, #7693	; 0x1e0d
  700104:	e1530002 	cmp	r3, r2
  700108:	0a000000 	beq	700110 <pages_manager_test+0xd8>
  70010c:	ebffffc1 	bl	700018 <test_fail>
  700110:	e3a01001 	mov	r1, #1
  700114:	e51b0008 	ldr	r0, [fp, #-8]
  700118:	eb000215 	bl	700974 <free_pages>
  70011c:	eb000161 	bl	7006a8 <get_kmem_first_size>
  700120:	e50b000c 	str	r0, [fp, #-12]
  700124:	e51b300c 	ldr	r3, [fp, #-12]
  700128:	e3012e0f 	movw	r2, #7695	; 0x1e0f
  70012c:	e1530002 	cmp	r3, r2
  700130:	0a000000 	beq	700138 <pages_manager_test+0x100>
  700134:	ebffffb7 	bl	700018 <test_fail>
  700138:	e59f3028 	ldr	r3, [pc, #40]	; 700168 <pages_manager_test+0x130>
  70013c:	e08f3003 	add	r3, pc, r3
  700140:	e1a00003 	mov	r0, r3
  700144:	eb00043b 	bl	701238 <uart_spin_puts>
  700148:	e59f301c 	ldr	r3, [pc, #28]	; 70016c <pages_manager_test+0x134>
  70014c:	e08f3003 	add	r3, pc, r3
  700150:	e1a00003 	mov	r0, r3
  700154:	eb000437 	bl	701238 <uart_spin_puts>
  700158:	e1a00000 	nop			; (mov r0, r0)
  70015c:	e24bd004 	sub	sp, fp, #4
  700160:	e8bd8800 	pop	{fp, pc}
  700164:	000013b0 	.word	0x000013b0
  700168:	000012bc 	.word	0x000012bc
  70016c:	000012c4 	.word	0x000012c4

00700170 <kernel_entry>:
  700170:	e92d4800 	push	{fp, lr}
  700174:	e28db004 	add	fp, sp, #4
  700178:	e24dd008 	sub	sp, sp, #8
  70017c:	e59f3038 	ldr	r3, [pc, #56]	; 7001bc <kernel_entry+0x4c>
  700180:	e08f3003 	add	r3, pc, r3
  700184:	e1a00003 	mov	r0, r3
  700188:	eb00042a 	bl	701238 <uart_spin_puts>
  70018c:	eb000129 	bl	700638 <init_first_page_table>
  700190:	e59f3028 	ldr	r3, [pc, #40]	; 7001c0 <kernel_entry+0x50>
  700194:	e08f3003 	add	r3, pc, r3
  700198:	e1a00003 	mov	r0, r3
  70019c:	eb000425 	bl	701238 <uart_spin_puts>
  7001a0:	e1a0300f 	mov	r3, pc
  7001a4:	e50b3008 	str	r3, [fp, #-8]
  7001a8:	e51b0008 	ldr	r0, [fp, #-8]
  7001ac:	eb00045e 	bl	70132c <puthex>
  7001b0:	eb00014a 	bl	7006e0 <alloc_init>
  7001b4:	ebffff9f 	bl	700038 <pages_manager_test>
  7001b8:	eafffffe 	b	7001b8 <kernel_entry+0x48>
  7001bc:	00001298 	.word	0x00001298
  7001c0:	00001294 	.word	0x00001294

007001c4 <enable_mmu>:
  7001c4:	e3a00c1f 	mov	r0, #7936	; 0x1f00
  7001c8:	e1a00800 	lsl	r0, r0, #16
  7001cc:	ee020f10 	mcr	15, 0, r0, cr2, cr0, {0}
  7001d0:	e3a00000 	mov	r0, #0
  7001d4:	ee080f17 	mcr	15, 0, r0, cr8, cr7, {0}
  7001d8:	e59f0038 	ldr	r0, [pc, #56]	; 700218 <enable_mmu+0x54>
  7001dc:	ee030f10 	mcr	15, 0, r0, cr3, cr0, {0}
  7001e0:	ee110f10 	mrc	15, 0, r0, cr1, cr0, {0}
  7001e4:	e3800001 	orr	r0, r0, #1
  7001e8:	ee010f10 	mcr	15, 0, r0, cr1, cr0, {0}
  7001ec:	e320f000 	nop	{0}
  7001f0:	e320f000 	nop	{0}
  7001f4:	e320f000 	nop	{0}
  7001f8:	e320f000 	nop	{0}
  7001fc:	e3a00102 	mov	r0, #-2147483648	; 0x80000000
  700200:	e08ee000 	add	lr, lr, r0
  700204:	e1a0f00e 	mov	pc, lr
  700208:	e320f000 	nop	{0}
  70020c:	e320f000 	nop	{0}
  700210:	e320f000 	nop	{0}
  700214:	e320f000 	nop	{0}
  700218:	55555555 	.word	0x55555555

0070021c <fill_pme_common>:
  70021c:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
  700220:	e28db000 	add	fp, sp, #0
  700224:	e24dd00c 	sub	sp, sp, #12
  700228:	e50b0008 	str	r0, [fp, #-8]
  70022c:	e51b2008 	ldr	r2, [fp, #-8]
  700230:	e5d23000 	ldrb	r3, [r2]
  700234:	e3a01002 	mov	r1, #2
  700238:	e7c13011 	bfi	r3, r1, #0, #2
  70023c:	e5c23000 	strb	r3, [r2]
  700240:	e51b2008 	ldr	r2, [fp, #-8]
  700244:	e5d23000 	ldrb	r3, [r2]
  700248:	e7c4321f 	bfc	r3, #4, #1
  70024c:	e5c23000 	strb	r3, [r2]
  700250:	e51b2008 	ldr	r2, [fp, #-8]
  700254:	e1d230b0 	ldrh	r3, [r2]
  700258:	e7c8329f 	bfc	r3, #5, #4
  70025c:	e1c230b0 	strh	r3, [r2]
  700260:	e51b2008 	ldr	r2, [fp, #-8]
  700264:	e5d23001 	ldrb	r3, [r2, #1]
  700268:	e7c1309f 	bfc	r3, #1, #1
  70026c:	e5c23001 	strb	r3, [r2, #1]
  700270:	e51b2008 	ldr	r2, [fp, #-8]
  700274:	e5d23002 	ldrb	r3, [r2, #2]
  700278:	e7c2311f 	bfc	r3, #2, #1
  70027c:	e5c23002 	strb	r3, [r2, #2]
  700280:	e51b2008 	ldr	r2, [fp, #-8]
  700284:	e5d23002 	ldrb	r3, [r2, #2]
  700288:	e7c3319f 	bfc	r3, #3, #1
  70028c:	e5c23002 	strb	r3, [r2, #2]
  700290:	e1a00000 	nop			; (mov r0, r0)
  700294:	e24bd000 	sub	sp, fp, #0
  700298:	e49db004 	pop	{fp}		; (ldr fp, [sp], #4)
  70029c:	e12fff1e 	bx	lr

007002a0 <init_mapping>:
  7002a0:	e92d4800 	push	{fp, lr}
  7002a4:	e28db004 	add	fp, sp, #4
  7002a8:	e24dd018 	sub	sp, sp, #24
  7002ac:	e3a0341f 	mov	r3, #520093696	; 0x1f000000
  7002b0:	e50b3014 	str	r3, [fp, #-20]	; 0xffffffec
  7002b4:	e3a03000 	mov	r3, #0
  7002b8:	e50b3008 	str	r3, [fp, #-8]
  7002bc:	ea000008 	b	7002e4 <init_mapping+0x44>
  7002c0:	e51b3008 	ldr	r3, [fp, #-8]
  7002c4:	e1a03103 	lsl	r3, r3, #2
  7002c8:	e51b2014 	ldr	r2, [fp, #-20]	; 0xffffffec
  7002cc:	e0823003 	add	r3, r2, r3
  7002d0:	e3a02000 	mov	r2, #0
  7002d4:	e5832000 	str	r2, [r3]
  7002d8:	e51b3008 	ldr	r3, [fp, #-8]
  7002dc:	e2833001 	add	r3, r3, #1
  7002e0:	e50b3008 	str	r3, [fp, #-8]
  7002e4:	e51b3008 	ldr	r3, [fp, #-8]
  7002e8:	e3530a02 	cmp	r3, #8192	; 0x2000
  7002ec:	bafffff3 	blt	7002c0 <init_mapping+0x20>
  7002f0:	e3a0341f 	mov	r3, #520093696	; 0x1f000000
  7002f4:	e50b3018 	str	r3, [fp, #-24]	; 0xffffffe8
  7002f8:	e3a03000 	mov	r3, #0
  7002fc:	e50b300c 	str	r3, [fp, #-12]
  700300:	ea000030 	b	7003c8 <init_mapping+0x128>
  700304:	e51b300c 	ldr	r3, [fp, #-12]
  700308:	e1a03a23 	lsr	r3, r3, #20
  70030c:	e1a03103 	lsl	r3, r3, #2
  700310:	e51b2018 	ldr	r2, [fp, #-24]	; 0xffffffe8
  700314:	e0823003 	add	r3, r2, r3
  700318:	e50b301c 	str	r3, [fp, #-28]	; 0xffffffe4
  70031c:	e51b001c 	ldr	r0, [fp, #-28]	; 0xffffffe4
  700320:	ebffffbd 	bl	70021c <fill_pme_common>
  700324:	e51b201c 	ldr	r2, [fp, #-28]	; 0xffffffe4
  700328:	e5d23000 	ldrb	r3, [r2]
  70032c:	e7c2311f 	bfc	r3, #2, #1
  700330:	e5c23000 	strb	r3, [r2]
  700334:	e51b201c 	ldr	r2, [fp, #-28]	; 0xffffffe4
  700338:	e5d23000 	ldrb	r3, [r2]
  70033c:	e7c3319f 	bfc	r3, #3, #1
  700340:	e5c23000 	strb	r3, [r2]
  700344:	e51b201c 	ldr	r2, [fp, #-28]	; 0xffffffe4
  700348:	e5d23001 	ldrb	r3, [r2, #1]
  70034c:	e3a01002 	mov	r1, #2
  700350:	e7c33111 	bfi	r3, r1, #2, #2
  700354:	e5c23001 	strb	r3, [r2, #1]
  700358:	e51b201c 	ldr	r2, [fp, #-28]	; 0xffffffe4
  70035c:	e5d23001 	ldrb	r3, [r2, #1]
  700360:	e7c6321f 	bfc	r3, #4, #3
  700364:	e5c23001 	strb	r3, [r2, #1]
  700368:	e51b201c 	ldr	r2, [fp, #-28]	; 0xffffffe4
  70036c:	e5d23001 	ldrb	r3, [r2, #1]
  700370:	e7c7339f 	bfc	r3, #7, #1
  700374:	e5c23001 	strb	r3, [r2, #1]
  700378:	e51b201c 	ldr	r2, [fp, #-28]	; 0xffffffe4
  70037c:	e5d23002 	ldrb	r3, [r2, #2]
  700380:	e3833001 	orr	r3, r3, #1
  700384:	e5c23002 	strb	r3, [r2, #2]
  700388:	e51b201c 	ldr	r2, [fp, #-28]	; 0xffffffe4
  70038c:	e5d23002 	ldrb	r3, [r2, #2]
  700390:	e7c1309f 	bfc	r3, #1, #1
  700394:	e5c23002 	strb	r3, [r2, #2]
  700398:	e51b300c 	ldr	r3, [fp, #-12]
  70039c:	e1a03a23 	lsr	r3, r3, #20
  7003a0:	e6ff3073 	uxth	r3, r3
  7003a4:	e7eb3053 	ubfx	r3, r3, #0, #12
  7003a8:	e6ff1073 	uxth	r1, r3
  7003ac:	e51b201c 	ldr	r2, [fp, #-28]	; 0xffffffe4
  7003b0:	e1d230b2 	ldrh	r3, [r2, #2]
  7003b4:	e7cf3211 	bfi	r3, r1, #4, #12
  7003b8:	e1c230b2 	strh	r3, [r2, #2]
  7003bc:	e51b300c 	ldr	r3, [fp, #-12]
  7003c0:	e2833601 	add	r3, r3, #1048576	; 0x100000
  7003c4:	e50b300c 	str	r3, [fp, #-12]
  7003c8:	e51b300c 	ldr	r3, [fp, #-12]
  7003cc:	e373021e 	cmn	r3, #-536870911	; 0xe0000001
  7003d0:	9affffcb 	bls	700304 <init_mapping+0x64>
  7003d4:	e3a03a02 	mov	r3, #8192	; 0x2000
  7003d8:	e3413f00 	movt	r3, #7936	; 0x1f00
  7003dc:	e50b3018 	str	r3, [fp, #-24]	; 0xffffffe8
  7003e0:	e3a03000 	mov	r3, #0
  7003e4:	e50b3010 	str	r3, [fp, #-16]
  7003e8:	ea000030 	b	7004b0 <init_mapping+0x210>
  7003ec:	e51b3010 	ldr	r3, [fp, #-16]
  7003f0:	e1a03a23 	lsr	r3, r3, #20
  7003f4:	e1a03103 	lsl	r3, r3, #2
  7003f8:	e51b2018 	ldr	r2, [fp, #-24]	; 0xffffffe8
  7003fc:	e0823003 	add	r3, r2, r3
  700400:	e50b301c 	str	r3, [fp, #-28]	; 0xffffffe4
  700404:	e51b001c 	ldr	r0, [fp, #-28]	; 0xffffffe4
  700408:	ebffff83 	bl	70021c <fill_pme_common>
  70040c:	e51b201c 	ldr	r2, [fp, #-28]	; 0xffffffe4
  700410:	e5d23000 	ldrb	r3, [r2]
  700414:	e7c2311f 	bfc	r3, #2, #1
  700418:	e5c23000 	strb	r3, [r2]
  70041c:	e51b201c 	ldr	r2, [fp, #-28]	; 0xffffffe4
  700420:	e5d23000 	ldrb	r3, [r2]
  700424:	e7c3319f 	bfc	r3, #3, #1
  700428:	e5c23000 	strb	r3, [r2]
  70042c:	e51b201c 	ldr	r2, [fp, #-28]	; 0xffffffe4
  700430:	e5d23001 	ldrb	r3, [r2, #1]
  700434:	e3a01002 	mov	r1, #2
  700438:	e7c33111 	bfi	r3, r1, #2, #2
  70043c:	e5c23001 	strb	r3, [r2, #1]
  700440:	e51b201c 	ldr	r2, [fp, #-28]	; 0xffffffe4
  700444:	e5d23001 	ldrb	r3, [r2, #1]
  700448:	e7c6321f 	bfc	r3, #4, #3
  70044c:	e5c23001 	strb	r3, [r2, #1]
  700450:	e51b201c 	ldr	r2, [fp, #-28]	; 0xffffffe4
  700454:	e5d23001 	ldrb	r3, [r2, #1]
  700458:	e7c7339f 	bfc	r3, #7, #1
  70045c:	e5c23001 	strb	r3, [r2, #1]
  700460:	e51b201c 	ldr	r2, [fp, #-28]	; 0xffffffe4
  700464:	e5d23002 	ldrb	r3, [r2, #2]
  700468:	e3833001 	orr	r3, r3, #1
  70046c:	e5c23002 	strb	r3, [r2, #2]
  700470:	e51b201c 	ldr	r2, [fp, #-28]	; 0xffffffe4
  700474:	e5d23002 	ldrb	r3, [r2, #2]
  700478:	e7c1309f 	bfc	r3, #1, #1
  70047c:	e5c23002 	strb	r3, [r2, #2]
  700480:	e51b3010 	ldr	r3, [fp, #-16]
  700484:	e1a03a23 	lsr	r3, r3, #20
  700488:	e6ff3073 	uxth	r3, r3
  70048c:	e7eb3053 	ubfx	r3, r3, #0, #12
  700490:	e6ff1073 	uxth	r1, r3
  700494:	e51b201c 	ldr	r2, [fp, #-28]	; 0xffffffe4
  700498:	e1d230b2 	ldrh	r3, [r2, #2]
  70049c:	e7cf3211 	bfi	r3, r1, #4, #12
  7004a0:	e1c230b2 	strh	r3, [r2, #2]
  7004a4:	e51b3010 	ldr	r3, [fp, #-16]
  7004a8:	e2833601 	add	r3, r3, #1048576	; 0x100000
  7004ac:	e50b3010 	str	r3, [fp, #-16]
  7004b0:	e51b3010 	ldr	r3, [fp, #-16]
  7004b4:	e373021e 	cmn	r3, #-536870911	; 0xe0000001
  7004b8:	9affffcb 	bls	7003ec <init_mapping+0x14c>
  7004bc:	e1a00000 	nop			; (mov r0, r0)
  7004c0:	e24bd004 	sub	sp, fp, #4
  7004c4:	e8bd8800 	pop	{fp, pc}

007004c8 <devices_mapping>:
  7004c8:	e92d4800 	push	{fp, lr}
  7004cc:	e28db004 	add	fp, sp, #4
  7004d0:	e24dd010 	sub	sp, sp, #16
  7004d4:	e3a0341f 	mov	r3, #520093696	; 0x1f000000
  7004d8:	e50b300c 	str	r3, [fp, #-12]
  7004dc:	e3a0320e 	mov	r3, #-536870912	; 0xe0000000
  7004e0:	e50b3008 	str	r3, [fp, #-8]
  7004e4:	ea00002f 	b	7005a8 <devices_mapping+0xe0>
  7004e8:	e51b3008 	ldr	r3, [fp, #-8]
  7004ec:	e1a03a23 	lsr	r3, r3, #20
  7004f0:	e1a03103 	lsl	r3, r3, #2
  7004f4:	e51b200c 	ldr	r2, [fp, #-12]
  7004f8:	e0823003 	add	r3, r2, r3
  7004fc:	e50b3010 	str	r3, [fp, #-16]
  700500:	e51b0010 	ldr	r0, [fp, #-16]
  700504:	ebffff44 	bl	70021c <fill_pme_common>
  700508:	e51b2010 	ldr	r2, [fp, #-16]
  70050c:	e5d23000 	ldrb	r3, [r2]
  700510:	e7c2311f 	bfc	r3, #2, #1
  700514:	e5c23000 	strb	r3, [r2]
  700518:	e51b2010 	ldr	r2, [fp, #-16]
  70051c:	e5d23000 	ldrb	r3, [r2]
  700520:	e7c3319f 	bfc	r3, #3, #1
  700524:	e5c23000 	strb	r3, [r2]
  700528:	e51b2010 	ldr	r2, [fp, #-16]
  70052c:	e5d23001 	ldrb	r3, [r2, #1]
  700530:	e383300c 	orr	r3, r3, #12
  700534:	e5c23001 	strb	r3, [r2, #1]
  700538:	e51b2010 	ldr	r2, [fp, #-16]
  70053c:	e5d23001 	ldrb	r3, [r2, #1]
  700540:	e7c6321f 	bfc	r3, #4, #3
  700544:	e5c23001 	strb	r3, [r2, #1]
  700548:	e51b2010 	ldr	r2, [fp, #-16]
  70054c:	e5d23001 	ldrb	r3, [r2, #1]
  700550:	e7c7339f 	bfc	r3, #7, #1
  700554:	e5c23001 	strb	r3, [r2, #1]
  700558:	e51b2010 	ldr	r2, [fp, #-16]
  70055c:	e5d23002 	ldrb	r3, [r2, #2]
  700560:	e3833001 	orr	r3, r3, #1
  700564:	e5c23002 	strb	r3, [r2, #2]
  700568:	e51b2010 	ldr	r2, [fp, #-16]
  70056c:	e5d23002 	ldrb	r3, [r2, #2]
  700570:	e7c1309f 	bfc	r3, #1, #1
  700574:	e5c23002 	strb	r3, [r2, #2]
  700578:	e51b3008 	ldr	r3, [fp, #-8]
  70057c:	e1a03a23 	lsr	r3, r3, #20
  700580:	e6ff3073 	uxth	r3, r3
  700584:	e7eb3053 	ubfx	r3, r3, #0, #12
  700588:	e6ff1073 	uxth	r1, r3
  70058c:	e51b2010 	ldr	r2, [fp, #-16]
  700590:	e1d230b2 	ldrh	r3, [r2, #2]
  700594:	e7cf3211 	bfi	r3, r1, #4, #12
  700598:	e1c230b2 	strh	r3, [r2, #2]
  70059c:	e51b3008 	ldr	r3, [fp, #-8]
  7005a0:	e2833601 	add	r3, r3, #1048576	; 0x100000
  7005a4:	e50b3008 	str	r3, [fp, #-8]
  7005a8:	e51b3008 	ldr	r3, [fp, #-8]
  7005ac:	e2432501 	sub	r2, r3, #4194304	; 0x400000
  7005b0:	e51b3008 	ldr	r3, [fp, #-8]
  7005b4:	e1520003 	cmp	r2, r3
  7005b8:	3affffca 	bcc	7004e8 <devices_mapping+0x20>
  7005bc:	e1a00000 	nop			; (mov r0, r0)
  7005c0:	e24bd004 	sub	sp, fp, #4
  7005c4:	e8bd8800 	pop	{fp, pc}

007005c8 <remove_low_mapping>:
  7005c8:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
  7005cc:	e28db000 	add	fp, sp, #0
  7005d0:	e24dd014 	sub	sp, sp, #20
  7005d4:	e3a0341f 	mov	r3, #520093696	; 0x1f000000
  7005d8:	e50b300c 	str	r3, [fp, #-12]
  7005dc:	e3a03000 	mov	r3, #0
  7005e0:	e50b3008 	str	r3, [fp, #-8]
  7005e4:	ea00000c 	b	70061c <remove_low_mapping+0x54>
  7005e8:	e51b3008 	ldr	r3, [fp, #-8]
  7005ec:	e1a03a23 	lsr	r3, r3, #20
  7005f0:	e1a03103 	lsl	r3, r3, #2
  7005f4:	e51b200c 	ldr	r2, [fp, #-12]
  7005f8:	e0823003 	add	r3, r2, r3
  7005fc:	e50b3010 	str	r3, [fp, #-16]
  700600:	e51b2010 	ldr	r2, [fp, #-16]
  700604:	e5d23000 	ldrb	r3, [r2]
  700608:	e7c1301f 	bfc	r3, #0, #2
  70060c:	e5c23000 	strb	r3, [r2]
  700610:	e51b3008 	ldr	r3, [fp, #-8]
  700614:	e2833601 	add	r3, r3, #1048576	; 0x100000
  700618:	e50b3008 	str	r3, [fp, #-8]
  70061c:	e51b3008 	ldr	r3, [fp, #-8]
  700620:	e373021e 	cmn	r3, #-536870911	; 0xe0000001
  700624:	9affffef 	bls	7005e8 <remove_low_mapping+0x20>
  700628:	e1a00000 	nop			; (mov r0, r0)
  70062c:	e24bd000 	sub	sp, fp, #0
  700630:	e49db004 	pop	{fp}		; (ldr fp, [sp], #4)
  700634:	e12fff1e 	bx	lr

00700638 <init_first_page_table>:
  700638:	e92d4800 	push	{fp, lr}
  70063c:	e28db004 	add	fp, sp, #4
  700640:	e24dd008 	sub	sp, sp, #8
  700644:	e59b1000 	ldr	r1, [fp]
  700648:	e3a00102 	mov	r0, #-2147483648	; 0x80000000
  70064c:	e0810000 	add	r0, r1, r0
  700650:	e58b0000 	str	r0, [fp]
  700654:	ebffff11 	bl	7002a0 <init_mapping>
  700658:	ebffff9a 	bl	7004c8 <devices_mapping>
  70065c:	ebfffed8 	bl	7001c4 <enable_mmu>
  700660:	e59f3038 	ldr	r3, [pc, #56]	; 7006a0 <init_first_page_table+0x68>
  700664:	e08f3003 	add	r3, pc, r3
  700668:	e1a00003 	mov	r0, r3
  70066c:	eb0002f1 	bl	701238 <uart_spin_puts>
  700670:	e59f302c 	ldr	r3, [pc, #44]	; 7006a4 <init_first_page_table+0x6c>
  700674:	e08f3003 	add	r3, pc, r3
  700678:	e1a00003 	mov	r0, r3
  70067c:	eb0002ed 	bl	701238 <uart_spin_puts>
  700680:	e1a0300f 	mov	r3, pc
  700684:	e50b3008 	str	r3, [fp, #-8]
  700688:	e51b0008 	ldr	r0, [fp, #-8]
  70068c:	eb000326 	bl	70132c <puthex>
  700690:	ebffffcc 	bl	7005c8 <remove_low_mapping>
  700694:	e1a00000 	nop			; (mov r0, r0)
  700698:	e24bd004 	sub	sp, fp, #4
  70069c:	e8bd8800 	pop	{fp, pc}
  7006a0:	00000ddc 	.word	0x00000ddc
  7006a4:	00000ddc 	.word	0x00000ddc

007006a8 <get_kmem_first_size>:
  7006a8:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
  7006ac:	e28db000 	add	fp, sp, #0
  7006b0:	e59f2020 	ldr	r2, [pc, #32]	; 7006d8 <get_kmem_first_size+0x30>
  7006b4:	e08f2002 	add	r2, pc, r2
  7006b8:	e59f301c 	ldr	r3, [pc, #28]	; 7006dc <get_kmem_first_size+0x34>
  7006bc:	e7923003 	ldr	r3, [r2, r3]
  7006c0:	e5933000 	ldr	r3, [r3]
  7006c4:	e5933004 	ldr	r3, [r3, #4]
  7006c8:	e1a00003 	mov	r0, r3
  7006cc:	e24bd000 	sub	sp, fp, #0
  7006d0:	e49db004 	pop	{fp}		; (ldr fp, [sp], #4)
  7006d4:	e12fff1e 	bx	lr
  7006d8:	fffff944 	.word	0xfffff944
  7006dc:	00000000 	.word	0x00000000

007006e0 <alloc_init>:
  7006e0:	e92d4800 	push	{fp, lr}
  7006e4:	e28db004 	add	fp, sp, #4
  7006e8:	e59f3068 	ldr	r3, [pc, #104]	; 700758 <alloc_init+0x78>
  7006ec:	e08f3003 	add	r3, pc, r3
  7006f0:	e59f2064 	ldr	r2, [pc, #100]	; 70075c <alloc_init+0x7c>
  7006f4:	e7932002 	ldr	r2, [r3, r2]
  7006f8:	e3a01102 	mov	r1, #-2147483648	; 0x80000000
  7006fc:	e5821000 	str	r1, [r2]
  700700:	e59f2054 	ldr	r2, [pc, #84]	; 70075c <alloc_init+0x7c>
  700704:	e7932002 	ldr	r2, [r3, r2]
  700708:	e5921000 	ldr	r1, [r2]
  70070c:	e3a02000 	mov	r2, #0
  700710:	e34820f0 	movt	r2, #33008	; 0x80f0
  700714:	e5812008 	str	r2, [r1, #8]
  700718:	e59f203c 	ldr	r2, [pc, #60]	; 70075c <alloc_init+0x7c>
  70071c:	e7932002 	ldr	r2, [r3, r2]
  700720:	e5922000 	ldr	r2, [r2]
  700724:	e3a01000 	mov	r1, #0
  700728:	e5821000 	str	r1, [r2]
  70072c:	e59f2028 	ldr	r2, [pc, #40]	; 70075c <alloc_init+0x7c>
  700730:	e7933002 	ldr	r3, [r3, r2]
  700734:	e5933000 	ldr	r3, [r3]
  700738:	e3012e10 	movw	r2, #7696	; 0x1e10
  70073c:	e5832004 	str	r2, [r3, #4]
  700740:	e59f3018 	ldr	r3, [pc, #24]	; 700760 <alloc_init+0x80>
  700744:	e08f3003 	add	r3, pc, r3
  700748:	e1a00003 	mov	r0, r3
  70074c:	eb0002b9 	bl	701238 <uart_spin_puts>
  700750:	e1a00000 	nop			; (mov r0, r0)
  700754:	e8bd8800 	pop	{fp, pc}
  700758:	fffff90c 	.word	0xfffff90c
  70075c:	00000000 	.word	0x00000000
  700760:	00000d38 	.word	0x00000d38

00700764 <alloc_pages>:
  700764:	e92d4810 	push	{r4, fp, lr}
  700768:	e28db008 	add	fp, sp, #8
  70076c:	e24dd01c 	sub	sp, sp, #28
  700770:	e50b0020 	str	r0, [fp, #-32]	; 0xffffffe0
  700774:	e59f4100 	ldr	r4, [pc, #256]	; 70087c <alloc_pages+0x118>
  700778:	e08f4004 	add	r4, pc, r4
  70077c:	e59f30fc 	ldr	r3, [pc, #252]	; 700880 <alloc_pages+0x11c>
  700780:	e08f3003 	add	r3, pc, r3
  700784:	e1a00003 	mov	r0, r3
  700788:	eb0002aa 	bl	701238 <uart_spin_puts>
  70078c:	e59f30f0 	ldr	r3, [pc, #240]	; 700884 <alloc_pages+0x120>
  700790:	e7943003 	ldr	r3, [r4, r3]
  700794:	e5933000 	ldr	r3, [r3]
  700798:	e50b3010 	str	r3, [fp, #-16]
  70079c:	e3a03000 	mov	r3, #0
  7007a0:	e50b3014 	str	r3, [fp, #-20]	; 0xffffffec
  7007a4:	e3a03000 	mov	r3, #0
  7007a8:	e50b3018 	str	r3, [fp, #-24]	; 0xffffffe8
  7007ac:	ea000029 	b	700858 <alloc_pages+0xf4>
  7007b0:	e51b3010 	ldr	r3, [fp, #-16]
  7007b4:	e5932004 	ldr	r2, [r3, #4]
  7007b8:	e51b3020 	ldr	r3, [fp, #-32]	; 0xffffffe0
  7007bc:	e1520003 	cmp	r2, r3
  7007c0:	da00000f 	ble	700804 <alloc_pages+0xa0>
  7007c4:	e51b3010 	ldr	r3, [fp, #-16]
  7007c8:	e5933008 	ldr	r3, [r3, #8]
  7007cc:	e51b2010 	ldr	r2, [fp, #-16]
  7007d0:	e5921004 	ldr	r1, [r2, #4]
  7007d4:	e51b2020 	ldr	r2, [fp, #-32]	; 0xffffffe0
  7007d8:	e0622001 	rsb	r2, r2, r1
  7007dc:	e1a02802 	lsl	r2, r2, #16
  7007e0:	e0833002 	add	r3, r3, r2
  7007e4:	e50b3018 	str	r3, [fp, #-24]	; 0xffffffe8
  7007e8:	e51b3010 	ldr	r3, [fp, #-16]
  7007ec:	e5932004 	ldr	r2, [r3, #4]
  7007f0:	e51b3020 	ldr	r3, [fp, #-32]	; 0xffffffe0
  7007f4:	e0632002 	rsb	r2, r3, r2
  7007f8:	e51b3010 	ldr	r3, [fp, #-16]
  7007fc:	e5832004 	str	r2, [r3, #4]
  700800:	ea000019 	b	70086c <alloc_pages+0x108>
  700804:	e51b3010 	ldr	r3, [fp, #-16]
  700808:	e5932004 	ldr	r2, [r3, #4]
  70080c:	e51b3020 	ldr	r3, [fp, #-32]	; 0xffffffe0
  700810:	e1520003 	cmp	r2, r3
  700814:	1a00000a 	bne	700844 <alloc_pages+0xe0>
  700818:	e51b3010 	ldr	r3, [fp, #-16]
  70081c:	e5933008 	ldr	r3, [r3, #8]
  700820:	e50b3018 	str	r3, [fp, #-24]	; 0xffffffe8
  700824:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700828:	e3530000 	cmp	r3, #0
  70082c:	0a00000d 	beq	700868 <alloc_pages+0x104>
  700830:	e51b3010 	ldr	r3, [fp, #-16]
  700834:	e5932000 	ldr	r2, [r3]
  700838:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  70083c:	e5832000 	str	r2, [r3]
  700840:	ea000008 	b	700868 <alloc_pages+0x104>
  700844:	e51b3010 	ldr	r3, [fp, #-16]
  700848:	e50b3014 	str	r3, [fp, #-20]	; 0xffffffec
  70084c:	e51b3010 	ldr	r3, [fp, #-16]
  700850:	e5933000 	ldr	r3, [r3]
  700854:	e50b3010 	str	r3, [fp, #-16]
  700858:	e51b3010 	ldr	r3, [fp, #-16]
  70085c:	e3530000 	cmp	r3, #0
  700860:	1affffd2 	bne	7007b0 <alloc_pages+0x4c>
  700864:	ea000000 	b	70086c <alloc_pages+0x108>
  700868:	e1a00000 	nop			; (mov r0, r0)
  70086c:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
  700870:	e1a00003 	mov	r0, r3
  700874:	e24bd008 	sub	sp, fp, #8
  700878:	e8bd8810 	pop	{r4, fp, pc}
  70087c:	fffff880 	.word	0xfffff880
  700880:	00000d10 	.word	0x00000d10
  700884:	00000000 	.word	0x00000000

00700888 <alloc_aligned_pages>:
  700888:	e92d4800 	push	{fp, lr}
  70088c:	e28db004 	add	fp, sp, #4
  700890:	e24dd018 	sub	sp, sp, #24
  700894:	e50b0018 	str	r0, [fp, #-24]	; 0xffffffe8
  700898:	e50b101c 	str	r1, [fp, #-28]	; 0xffffffe4
  70089c:	e3a02001 	mov	r2, #1
  7008a0:	e51b301c 	ldr	r3, [fp, #-28]	; 0xffffffe4
  7008a4:	e1a02312 	lsl	r2, r2, r3
  7008a8:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
  7008ac:	e0823003 	add	r3, r2, r3
  7008b0:	e2433001 	sub	r3, r3, #1
  7008b4:	e1a00003 	mov	r0, r3
  7008b8:	ebffffa9 	bl	700764 <alloc_pages>
  7008bc:	e50b0008 	str	r0, [fp, #-8]
  7008c0:	e51b3008 	ldr	r3, [fp, #-8]
  7008c4:	e1a03823 	lsr	r3, r3, #16
  7008c8:	e3a01001 	mov	r1, #1
  7008cc:	e51b201c 	ldr	r2, [fp, #-28]	; 0xffffffe4
  7008d0:	e1a01211 	lsl	r1, r1, r2
  7008d4:	e51b2018 	ldr	r2, [fp, #-24]	; 0xffffffe8
  7008d8:	e0812002 	add	r2, r1, r2
  7008dc:	e0833002 	add	r3, r3, r2
  7008e0:	e2433001 	sub	r3, r3, #1
  7008e4:	e50b300c 	str	r3, [fp, #-12]
  7008e8:	e51b3008 	ldr	r3, [fp, #-8]
  7008ec:	e1a03823 	lsr	r3, r3, #16
  7008f0:	e50b3010 	str	r3, [fp, #-16]
  7008f4:	e3a02001 	mov	r2, #1
  7008f8:	e51b301c 	ldr	r3, [fp, #-28]	; 0xffffffe4
  7008fc:	e1a03312 	lsl	r3, r2, r3
  700900:	e2432001 	sub	r2, r3, #1
  700904:	e51b3010 	ldr	r3, [fp, #-16]
  700908:	e0033002 	and	r3, r3, r2
  70090c:	e3530000 	cmp	r3, #0
  700910:	1a00000d 	bne	70094c <alloc_aligned_pages+0xc4>
  700914:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
  700918:	e1a03803 	lsl	r3, r3, #16
  70091c:	e1a02003 	mov	r2, r3
  700920:	e51b3008 	ldr	r3, [fp, #-8]
  700924:	e0833002 	add	r3, r3, r2
  700928:	e50b3014 	str	r3, [fp, #-20]	; 0xffffffec
  70092c:	e51b200c 	ldr	r2, [fp, #-12]
  700930:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700934:	e0633002 	rsb	r3, r3, r2
  700938:	e1a01003 	mov	r1, r3
  70093c:	e51b0014 	ldr	r0, [fp, #-20]	; 0xffffffec
  700940:	eb00000b 	bl	700974 <free_pages>
  700944:	e51b3008 	ldr	r3, [fp, #-8]
  700948:	ea000006 	b	700968 <alloc_aligned_pages+0xe0>
  70094c:	e3a01001 	mov	r1, #1
  700950:	e51b0008 	ldr	r0, [fp, #-8]
  700954:	eb000006 	bl	700974 <free_pages>
  700958:	e51b3008 	ldr	r3, [fp, #-8]
  70095c:	e2833801 	add	r3, r3, #65536	; 0x10000
  700960:	e50b3008 	str	r3, [fp, #-8]
  700964:	eaffffdf 	b	7008e8 <alloc_aligned_pages+0x60>
  700968:	e1a00003 	mov	r0, r3
  70096c:	e24bd004 	sub	sp, fp, #4
  700970:	e8bd8800 	pop	{fp, pc}

00700974 <free_pages>:
  700974:	e92d4810 	push	{r4, fp, lr}
  700978:	e28db008 	add	fp, sp, #8
  70097c:	e24dd01c 	sub	sp, sp, #28
  700980:	e50b0020 	str	r0, [fp, #-32]	; 0xffffffe0
  700984:	e50b1024 	str	r1, [fp, #-36]	; 0xffffffdc
  700988:	e59f4280 	ldr	r4, [pc, #640]	; 700c10 <free_pages+0x29c>
  70098c:	e08f4004 	add	r4, pc, r4
  700990:	e51b3024 	ldr	r3, [fp, #-36]	; 0xffffffdc
  700994:	e3530000 	cmp	r3, #0
  700998:	0a000099 	beq	700c04 <free_pages+0x290>
  70099c:	e51b3020 	ldr	r3, [fp, #-32]	; 0xffffffe0
  7009a0:	e6ff3073 	uxth	r3, r3
  7009a4:	e3530000 	cmp	r3, #0
  7009a8:	0a000004 	beq	7009c0 <free_pages+0x4c>
  7009ac:	e59f3260 	ldr	r3, [pc, #608]	; 700c14 <free_pages+0x2a0>
  7009b0:	e08f3003 	add	r3, pc, r3
  7009b4:	e1a00003 	mov	r0, r3
  7009b8:	eb00021e 	bl	701238 <uart_spin_puts>
  7009bc:	ea000091 	b	700c08 <free_pages+0x294>
  7009c0:	e59f3250 	ldr	r3, [pc, #592]	; 700c18 <free_pages+0x2a4>
  7009c4:	e08f3003 	add	r3, pc, r3
  7009c8:	e1a00003 	mov	r0, r3
  7009cc:	eb000219 	bl	701238 <uart_spin_puts>
  7009d0:	e59f3244 	ldr	r3, [pc, #580]	; 700c1c <free_pages+0x2a8>
  7009d4:	e7943003 	ldr	r3, [r4, r3]
  7009d8:	e5933000 	ldr	r3, [r3]
  7009dc:	e50b3010 	str	r3, [fp, #-16]
  7009e0:	e3a03000 	mov	r3, #0
  7009e4:	e50b3014 	str	r3, [fp, #-20]	; 0xffffffec
  7009e8:	ea000051 	b	700b34 <free_pages+0x1c0>
  7009ec:	e51b3010 	ldr	r3, [fp, #-16]
  7009f0:	e5933008 	ldr	r3, [r3, #8]
  7009f4:	e1a02003 	mov	r2, r3
  7009f8:	e51b3020 	ldr	r3, [fp, #-32]	; 0xffffffe0
  7009fc:	e1520003 	cmp	r2, r3
  700a00:	9a000046 	bls	700b20 <free_pages+0x1ac>
  700a04:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700a08:	e3530000 	cmp	r3, #0
  700a0c:	0a000011 	beq	700a58 <free_pages+0xe4>
  700a10:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700a14:	e5933008 	ldr	r3, [r3, #8]
  700a18:	e51b2014 	ldr	r2, [fp, #-20]	; 0xffffffec
  700a1c:	e5922004 	ldr	r2, [r2, #4]
  700a20:	e1a02802 	lsl	r2, r2, #16
  700a24:	e0832002 	add	r2, r3, r2
  700a28:	e51b3020 	ldr	r3, [fp, #-32]	; 0xffffffe0
  700a2c:	e1520003 	cmp	r2, r3
  700a30:	1a000008 	bne	700a58 <free_pages+0xe4>
  700a34:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700a38:	e5933004 	ldr	r3, [r3, #4]
  700a3c:	e1a02003 	mov	r2, r3
  700a40:	e51b3024 	ldr	r3, [fp, #-36]	; 0xffffffdc
  700a44:	e0823003 	add	r3, r2, r3
  700a48:	e1a02003 	mov	r2, r3
  700a4c:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700a50:	e5832004 	str	r2, [r3, #4]
  700a54:	ea000017 	b	700ab8 <free_pages+0x144>
  700a58:	e51b3020 	ldr	r3, [fp, #-32]	; 0xffffffe0
  700a5c:	e50b3018 	str	r3, [fp, #-24]	; 0xffffffe8
  700a60:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
  700a64:	e51b2010 	ldr	r2, [fp, #-16]
  700a68:	e5832000 	str	r2, [r3]
  700a6c:	e51b2024 	ldr	r2, [fp, #-36]	; 0xffffffdc
  700a70:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
  700a74:	e5832004 	str	r2, [r3, #4]
  700a78:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
  700a7c:	e51b2020 	ldr	r2, [fp, #-32]	; 0xffffffe0
  700a80:	e5832008 	str	r2, [r3, #8]
  700a84:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700a88:	e3530000 	cmp	r3, #0
  700a8c:	0a000003 	beq	700aa0 <free_pages+0x12c>
  700a90:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700a94:	e51b2018 	ldr	r2, [fp, #-24]	; 0xffffffe8
  700a98:	e5832000 	str	r2, [r3]
  700a9c:	ea000003 	b	700ab0 <free_pages+0x13c>
  700aa0:	e59f3174 	ldr	r3, [pc, #372]	; 700c1c <free_pages+0x2a8>
  700aa4:	e7943003 	ldr	r3, [r4, r3]
  700aa8:	e51b2018 	ldr	r2, [fp, #-24]	; 0xffffffe8
  700aac:	e5832000 	str	r2, [r3]
  700ab0:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
  700ab4:	e50b3014 	str	r3, [fp, #-20]	; 0xffffffec
  700ab8:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700abc:	e5933008 	ldr	r3, [r3, #8]
  700ac0:	e51b2014 	ldr	r2, [fp, #-20]	; 0xffffffec
  700ac4:	e5922004 	ldr	r2, [r2, #4]
  700ac8:	e1a02802 	lsl	r2, r2, #16
  700acc:	e0832002 	add	r2, r3, r2
  700ad0:	e51b3010 	ldr	r3, [fp, #-16]
  700ad4:	e5933008 	ldr	r3, [r3, #8]
  700ad8:	e1520003 	cmp	r2, r3
  700adc:	1a00000a 	bne	700b0c <free_pages+0x198>
  700ae0:	e51b3010 	ldr	r3, [fp, #-16]
  700ae4:	e5932000 	ldr	r2, [r3]
  700ae8:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700aec:	e5832000 	str	r2, [r3]
  700af0:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700af4:	e5932004 	ldr	r2, [r3, #4]
  700af8:	e51b3010 	ldr	r3, [fp, #-16]
  700afc:	e5933004 	ldr	r3, [r3, #4]
  700b00:	e0822003 	add	r2, r2, r3
  700b04:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700b08:	e5832004 	str	r2, [r3, #4]
  700b0c:	e59f310c 	ldr	r3, [pc, #268]	; 700c20 <free_pages+0x2ac>
  700b10:	e08f3003 	add	r3, pc, r3
  700b14:	e1a00003 	mov	r0, r3
  700b18:	eb0001c6 	bl	701238 <uart_spin_puts>
  700b1c:	ea000039 	b	700c08 <free_pages+0x294>
  700b20:	e51b3010 	ldr	r3, [fp, #-16]
  700b24:	e50b3014 	str	r3, [fp, #-20]	; 0xffffffec
  700b28:	e51b3010 	ldr	r3, [fp, #-16]
  700b2c:	e5933000 	ldr	r3, [r3]
  700b30:	e50b3010 	str	r3, [fp, #-16]
  700b34:	e51b3010 	ldr	r3, [fp, #-16]
  700b38:	e3530000 	cmp	r3, #0
  700b3c:	1affffaa 	bne	7009ec <free_pages+0x78>
  700b40:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700b44:	e3530000 	cmp	r3, #0
  700b48:	0a000011 	beq	700b94 <free_pages+0x220>
  700b4c:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700b50:	e5933008 	ldr	r3, [r3, #8]
  700b54:	e51b2014 	ldr	r2, [fp, #-20]	; 0xffffffec
  700b58:	e5922004 	ldr	r2, [r2, #4]
  700b5c:	e1a02802 	lsl	r2, r2, #16
  700b60:	e0832002 	add	r2, r3, r2
  700b64:	e51b3020 	ldr	r3, [fp, #-32]	; 0xffffffe0
  700b68:	e1520003 	cmp	r2, r3
  700b6c:	1a000008 	bne	700b94 <free_pages+0x220>
  700b70:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700b74:	e5933004 	ldr	r3, [r3, #4]
  700b78:	e1a02003 	mov	r2, r3
  700b7c:	e51b3024 	ldr	r3, [fp, #-36]	; 0xffffffdc
  700b80:	e0823003 	add	r3, r2, r3
  700b84:	e1a02003 	mov	r2, r3
  700b88:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700b8c:	e5832004 	str	r2, [r3, #4]
  700b90:	ea000015 	b	700bec <free_pages+0x278>
  700b94:	e51b3020 	ldr	r3, [fp, #-32]	; 0xffffffe0
  700b98:	e50b301c 	str	r3, [fp, #-28]	; 0xffffffe4
  700b9c:	e51b301c 	ldr	r3, [fp, #-28]	; 0xffffffe4
  700ba0:	e3a02000 	mov	r2, #0
  700ba4:	e5832000 	str	r2, [r3]
  700ba8:	e51b2024 	ldr	r2, [fp, #-36]	; 0xffffffdc
  700bac:	e51b301c 	ldr	r3, [fp, #-28]	; 0xffffffe4
  700bb0:	e5832004 	str	r2, [r3, #4]
  700bb4:	e51b301c 	ldr	r3, [fp, #-28]	; 0xffffffe4
  700bb8:	e51b2020 	ldr	r2, [fp, #-32]	; 0xffffffe0
  700bbc:	e5832008 	str	r2, [r3, #8]
  700bc0:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700bc4:	e3530000 	cmp	r3, #0
  700bc8:	0a000003 	beq	700bdc <free_pages+0x268>
  700bcc:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700bd0:	e51b201c 	ldr	r2, [fp, #-28]	; 0xffffffe4
  700bd4:	e5832000 	str	r2, [r3]
  700bd8:	ea000003 	b	700bec <free_pages+0x278>
  700bdc:	e59f3038 	ldr	r3, [pc, #56]	; 700c1c <free_pages+0x2a8>
  700be0:	e7943003 	ldr	r3, [r4, r3]
  700be4:	e51b201c 	ldr	r2, [fp, #-28]	; 0xffffffe4
  700be8:	e5832000 	str	r2, [r3]
  700bec:	e59f3030 	ldr	r3, [pc, #48]	; 700c24 <free_pages+0x2b0>
  700bf0:	e08f3003 	add	r3, pc, r3
  700bf4:	e1a00003 	mov	r0, r3
  700bf8:	eb00018e 	bl	701238 <uart_spin_puts>
  700bfc:	e1a00000 	nop			; (mov r0, r0)
  700c00:	ea000000 	b	700c08 <free_pages+0x294>
  700c04:	e1a00000 	nop			; (mov r0, r0)
  700c08:	e24bd008 	sub	sp, fp, #8
  700c0c:	e8bd8810 	pop	{r4, fp, pc}
  700c10:	fffff66c 	.word	0xfffff66c
  700c14:	00000af0 	.word	0x00000af0
  700c18:	00000b08 	.word	0x00000b08
  700c1c:	00000000 	.word	0x00000000
  700c20:	000009cc 	.word	0x000009cc
  700c24:	000008ec 	.word	0x000008ec

00700c28 <fail>:
  700c28:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
  700c2c:	e28db000 	add	fp, sp, #0
  700c30:	eafffffe 	b	700c30 <fail+0x8>

00700c34 <slab_init>:
  700c34:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
  700c38:	e28db000 	add	fp, sp, #0
  700c3c:	e24dd024 	sub	sp, sp, #36	; 0x24
  700c40:	e50b0018 	str	r0, [fp, #-24]	; 0xffffffe8
  700c44:	e50b101c 	str	r1, [fp, #-28]	; 0xffffffe4
  700c48:	e50b2020 	str	r2, [fp, #-32]	; 0xffffffe0
  700c4c:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
  700c50:	e50b3008 	str	r3, [fp, #-8]
  700c54:	e51b3008 	ldr	r3, [fp, #-8]
  700c58:	e3a02000 	mov	r2, #0
  700c5c:	e5832000 	str	r2, [r3]
  700c60:	e3a03000 	mov	r3, #0
  700c64:	e50b300c 	str	r3, [fp, #-12]
  700c68:	ea000037 	b	700d4c <slab_init+0x118>
  700c6c:	e51b3020 	ldr	r3, [fp, #-32]	; 0xffffffe0
  700c70:	e51b2018 	ldr	r2, [fp, #-24]	; 0xffffffe8
  700c74:	e0823003 	add	r3, r2, r3
  700c78:	e50b3010 	str	r3, [fp, #-16]
  700c7c:	ea00001b 	b	700cf0 <slab_init+0xbc>
  700c80:	e51b3010 	ldr	r3, [fp, #-16]
  700c84:	e50b3014 	str	r3, [fp, #-20]	; 0xffffffec
  700c88:	e51b3008 	ldr	r3, [fp, #-8]
  700c8c:	e5933000 	ldr	r3, [r3]
  700c90:	e2832001 	add	r2, r3, #1
  700c94:	e51b3008 	ldr	r3, [fp, #-8]
  700c98:	e5832000 	str	r2, [r3]
  700c9c:	e51b2020 	ldr	r2, [fp, #-32]	; 0xffffffe0
  700ca0:	e51b3010 	ldr	r3, [fp, #-16]
  700ca4:	e0822003 	add	r2, r2, r3
  700ca8:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
  700cac:	e2833801 	add	r3, r3, #65536	; 0x10000
  700cb0:	e1520003 	cmp	r2, r3
  700cb4:	1a000003 	bne	700cc8 <slab_init+0x94>
  700cb8:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700cbc:	e3a02000 	mov	r2, #0
  700cc0:	e5832000 	str	r2, [r3]
  700cc4:	ea000005 	b	700ce0 <slab_init+0xac>
  700cc8:	e51b2020 	ldr	r2, [fp, #-32]	; 0xffffffe0
  700ccc:	e51b3010 	ldr	r3, [fp, #-16]
  700cd0:	e0823003 	add	r3, r2, r3
  700cd4:	e1a02003 	mov	r2, r3
  700cd8:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700cdc:	e5832000 	str	r2, [r3]
  700ce0:	e51b3020 	ldr	r3, [fp, #-32]	; 0xffffffe0
  700ce4:	e51b2010 	ldr	r2, [fp, #-16]
  700ce8:	e0823003 	add	r3, r2, r3
  700cec:	e50b3010 	str	r3, [fp, #-16]
  700cf0:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
  700cf4:	e2832801 	add	r2, r3, #65536	; 0x10000
  700cf8:	e51b3010 	ldr	r3, [fp, #-16]
  700cfc:	e1520003 	cmp	r2, r3
  700d00:	8affffde 	bhi	700c80 <slab_init+0x4c>
  700d04:	e51b200c 	ldr	r2, [fp, #-12]
  700d08:	e51b301c 	ldr	r3, [fp, #-28]	; 0xffffffe4
  700d0c:	e1520003 	cmp	r2, r3
  700d10:	aa000004 	bge	700d28 <slab_init+0xf4>
  700d14:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
  700d18:	e2833801 	add	r3, r3, #65536	; 0x10000
  700d1c:	e1a02003 	mov	r2, r3
  700d20:	e51b3008 	ldr	r3, [fp, #-8]
  700d24:	e5832008 	str	r2, [r3, #8]
  700d28:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
  700d2c:	e2833801 	add	r3, r3, #65536	; 0x10000
  700d30:	e50b3018 	str	r3, [fp, #-24]	; 0xffffffe8
  700d34:	e51b3008 	ldr	r3, [fp, #-8]
  700d38:	e5933008 	ldr	r3, [r3, #8]
  700d3c:	e50b3008 	str	r3, [fp, #-8]
  700d40:	e51b300c 	ldr	r3, [fp, #-12]
  700d44:	e2833001 	add	r3, r3, #1
  700d48:	e50b300c 	str	r3, [fp, #-12]
  700d4c:	e51b200c 	ldr	r2, [fp, #-12]
  700d50:	e51b301c 	ldr	r3, [fp, #-28]	; 0xffffffe4
  700d54:	e1520003 	cmp	r2, r3
  700d58:	baffffc3 	blt	700c6c <slab_init+0x38>
  700d5c:	e1a00000 	nop			; (mov r0, r0)
  700d60:	e24bd000 	sub	sp, fp, #0
  700d64:	e49db004 	pop	{fp}		; (ldr fp, [sp], #4)
  700d68:	e12fff1e 	bx	lr

00700d6c <slab_pools_init>:
  700d6c:	e92d4810 	push	{r4, fp, lr}
  700d70:	e28db008 	add	fp, sp, #8
  700d74:	e24dd014 	sub	sp, sp, #20
  700d78:	e59f4080 	ldr	r4, [pc, #128]	; 700e00 <slab_pools_init+0x94>
  700d7c:	e08f4004 	add	r4, pc, r4
  700d80:	e3a00001 	mov	r0, #1
  700d84:	ebfffe76 	bl	700764 <alloc_pages>
  700d88:	e1a03000 	mov	r3, r0
  700d8c:	e50b3018 	str	r3, [fp, #-24]	; 0xffffffe8
  700d90:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
  700d94:	e50b301c 	str	r3, [fp, #-28]	; 0xffffffe4
  700d98:	e3a03000 	mov	r3, #0
  700d9c:	e50b3010 	str	r3, [fp, #-16]
  700da0:	e3a03006 	mov	r3, #6
  700da4:	e2433001 	sub	r3, r3, #1
  700da8:	e50b3014 	str	r3, [fp, #-20]	; 0xffffffec
  700dac:	ea00000d 	b	700de8 <slab_pools_init+0x7c>
  700db0:	e59f304c 	ldr	r3, [pc, #76]	; 700e04 <slab_pools_init+0x98>
  700db4:	e7943003 	ldr	r3, [r4, r3]
  700db8:	e51b2014 	ldr	r2, [fp, #-20]	; 0xffffffec
  700dbc:	e7932102 	ldr	r2, [r3, r2, lsl #2]
  700dc0:	e51b301c 	ldr	r3, [fp, #-28]	; 0xffffffe4
  700dc4:	e5832000 	str	r2, [r3]
  700dc8:	e51b301c 	ldr	r3, [fp, #-28]	; 0xffffffe4
  700dcc:	e51b2010 	ldr	r2, [fp, #-16]
  700dd0:	e583200c 	str	r2, [r3, #12]
  700dd4:	e51b301c 	ldr	r3, [fp, #-28]	; 0xffffffe4
  700dd8:	e50b3010 	str	r3, [fp, #-16]
  700ddc:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700de0:	e2833001 	add	r3, r3, #1
  700de4:	e50b3014 	str	r3, [fp, #-20]	; 0xffffffec
  700de8:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700dec:	e3530000 	cmp	r3, #0
  700df0:	aaffffee 	bge	700db0 <slab_pools_init+0x44>
  700df4:	e1a00000 	nop			; (mov r0, r0)
  700df8:	e24bd008 	sub	sp, fp, #8
  700dfc:	e8bd8810 	pop	{r4, fp, pc}
  700e00:	fffff27c 	.word	0xfffff27c
  700e04:	00000004 	.word	0x00000004

00700e08 <slab_alloc>:
  700e08:	e92d4800 	push	{fp, lr}
  700e0c:	e28db004 	add	fp, sp, #4
  700e10:	e24dd010 	sub	sp, sp, #16
  700e14:	e50b0010 	str	r0, [fp, #-16]
  700e18:	e50b1014 	str	r1, [fp, #-20]	; 0xffffffec
  700e1c:	e3a00004 	mov	r0, #4
  700e20:	ebfffe4f 	bl	700764 <alloc_pages>
  700e24:	e1a03000 	mov	r3, r0
  700e28:	e50b3008 	str	r3, [fp, #-8]
  700e2c:	e51b2008 	ldr	r2, [fp, #-8]
  700e30:	e51b3010 	ldr	r3, [fp, #-16]
  700e34:	e5832010 	str	r2, [r3, #16]
  700e38:	e51b3010 	ldr	r3, [fp, #-16]
  700e3c:	e5933000 	ldr	r3, [r3]
  700e40:	e1a02003 	mov	r2, r3
  700e44:	e3a01004 	mov	r1, #4
  700e48:	e51b0008 	ldr	r0, [fp, #-8]
  700e4c:	ebffff78 	bl	700c34 <slab_init>
  700e50:	e51b3010 	ldr	r3, [fp, #-16]
  700e54:	e5933010 	ldr	r3, [r3, #16]
  700e58:	e5932000 	ldr	r2, [r3]
  700e5c:	e51b3010 	ldr	r3, [fp, #-16]
  700e60:	e5832004 	str	r2, [r3, #4]
  700e64:	e1a00000 	nop			; (mov r0, r0)
  700e68:	e1a00003 	mov	r0, r3
  700e6c:	e24bd004 	sub	sp, fp, #4
  700e70:	e8bd8800 	pop	{fp, pc}

00700e74 <slab_free>:
  700e74:	e92d4800 	push	{fp, lr}
  700e78:	e28db004 	add	fp, sp, #4
  700e7c:	e24dd010 	sub	sp, sp, #16
  700e80:	e50b0008 	str	r0, [fp, #-8]
  700e84:	e50b100c 	str	r1, [fp, #-12]
  700e88:	e50b2010 	str	r2, [fp, #-16]
  700e8c:	e51b300c 	ldr	r3, [fp, #-12]
  700e90:	e5932010 	ldr	r2, [r3, #16]
  700e94:	e51b3008 	ldr	r3, [fp, #-8]
  700e98:	e1520003 	cmp	r2, r3
  700e9c:	1a000004 	bne	700eb4 <slab_free+0x40>
  700ea0:	e51b3008 	ldr	r3, [fp, #-8]
  700ea4:	e5932008 	ldr	r2, [r3, #8]
  700ea8:	e51b300c 	ldr	r3, [fp, #-12]
  700eac:	e5832010 	str	r2, [r3, #16]
  700eb0:	ea000003 	b	700ec4 <slab_free+0x50>
  700eb4:	e51b3008 	ldr	r3, [fp, #-8]
  700eb8:	e5932008 	ldr	r2, [r3, #8]
  700ebc:	e51b3010 	ldr	r3, [fp, #-16]
  700ec0:	e5832008 	str	r2, [r3, #8]
  700ec4:	e3a01001 	mov	r1, #1
  700ec8:	e51b0008 	ldr	r0, [fp, #-8]
  700ecc:	ebfffea8 	bl	700974 <free_pages>
  700ed0:	e1a00000 	nop			; (mov r0, r0)
  700ed4:	e24bd004 	sub	sp, fp, #4
  700ed8:	e8bd8800 	pop	{fp, pc}

00700edc <is_in_slab>:
  700edc:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
  700ee0:	e28db000 	add	fp, sp, #0
  700ee4:	e24dd01c 	sub	sp, sp, #28
  700ee8:	e50b0010 	str	r0, [fp, #-16]
  700eec:	e50b1014 	str	r1, [fp, #-20]	; 0xffffffec
  700ef0:	e50b2018 	str	r2, [fp, #-24]	; 0xffffffe8
  700ef4:	e51b3010 	ldr	r3, [fp, #-16]
  700ef8:	e50b3008 	str	r3, [fp, #-8]
  700efc:	e51b2018 	ldr	r2, [fp, #-24]	; 0xffffffe8
  700f00:	e51b3008 	ldr	r3, [fp, #-8]
  700f04:	e0822003 	add	r2, r2, r3
  700f08:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700f0c:	e1520003 	cmp	r2, r3
  700f10:	8a000006 	bhi	700f30 <is_in_slab+0x54>
  700f14:	e51b3008 	ldr	r3, [fp, #-8]
  700f18:	e2832801 	add	r2, r3, #65536	; 0x10000
  700f1c:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  700f20:	e1520003 	cmp	r2, r3
  700f24:	3a000001 	bcc	700f30 <is_in_slab+0x54>
  700f28:	e3a03001 	mov	r3, #1
  700f2c:	ea000000 	b	700f34 <is_in_slab+0x58>
  700f30:	e3a03000 	mov	r3, #0
  700f34:	e1a00003 	mov	r0, r3
  700f38:	e24bd000 	sub	sp, fp, #0
  700f3c:	e49db004 	pop	{fp}		; (ldr fp, [sp], #4)
  700f40:	e12fff1e 	bx	lr

00700f44 <obj_free>:
  700f44:	e92d4800 	push	{fp, lr}
  700f48:	e28db004 	add	fp, sp, #4
  700f4c:	e24dd018 	sub	sp, sp, #24
  700f50:	e50b0018 	str	r0, [fp, #-24]	; 0xffffffe8
  700f54:	e50b101c 	str	r1, [fp, #-28]	; 0xffffffe4
  700f58:	e59f2168 	ldr	r2, [pc, #360]	; 7010c8 <obj_free+0x184>
  700f5c:	e08f2002 	add	r2, pc, r2
  700f60:	e59f3164 	ldr	r3, [pc, #356]	; 7010cc <obj_free+0x188>
  700f64:	e7923003 	ldr	r3, [r2, r3]
  700f68:	e5933000 	ldr	r3, [r3]
  700f6c:	e50b3008 	str	r3, [fp, #-8]
  700f70:	ea000048 	b	701098 <obj_free+0x154>
  700f74:	e51b3008 	ldr	r3, [fp, #-8]
  700f78:	e5932000 	ldr	r2, [r3]
  700f7c:	e51b301c 	ldr	r3, [fp, #-28]	; 0xffffffe4
  700f80:	e1520003 	cmp	r2, r3
  700f84:	da000040 	ble	70108c <obj_free+0x148>
  700f88:	e51b3008 	ldr	r3, [fp, #-8]
  700f8c:	e5933000 	ldr	r3, [r3]
  700f90:	e2433001 	sub	r3, r3, #1
  700f94:	e1a02003 	mov	r2, r3
  700f98:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
  700f9c:	e0033002 	and	r3, r3, r2
  700fa0:	e3530000 	cmp	r3, #0
  700fa4:	0a000004 	beq	700fbc <obj_free+0x78>
  700fa8:	e59f3120 	ldr	r3, [pc, #288]	; 7010d0 <obj_free+0x18c>
  700fac:	e08f3003 	add	r3, pc, r3
  700fb0:	e1a00003 	mov	r0, r3
  700fb4:	eb00009f 	bl	701238 <uart_spin_puts>
  700fb8:	ebffff1a 	bl	700c28 <fail>
  700fbc:	e3a03000 	mov	r3, #0
  700fc0:	e50b300c 	str	r3, [fp, #-12]
  700fc4:	e51b3008 	ldr	r3, [fp, #-8]
  700fc8:	e5933010 	ldr	r3, [r3, #16]
  700fcc:	e50b3010 	str	r3, [fp, #-16]
  700fd0:	ea00002a 	b	701080 <obj_free+0x13c>
  700fd4:	e51b3008 	ldr	r3, [fp, #-8]
  700fd8:	e5933000 	ldr	r3, [r3]
  700fdc:	e1a02003 	mov	r2, r3
  700fe0:	e51b1018 	ldr	r1, [fp, #-24]	; 0xffffffe8
  700fe4:	e51b0010 	ldr	r0, [fp, #-16]
  700fe8:	ebffffbb 	bl	700edc <is_in_slab>
  700fec:	e1a03000 	mov	r3, r0
  700ff0:	e3530000 	cmp	r3, #0
  700ff4:	0a00001c 	beq	70106c <obj_free+0x128>
  700ff8:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
  700ffc:	e50b3014 	str	r3, [fp, #-20]	; 0xffffffec
  701000:	e51b3010 	ldr	r3, [fp, #-16]
  701004:	e5932004 	ldr	r2, [r3, #4]
  701008:	e51b3014 	ldr	r3, [fp, #-20]	; 0xffffffec
  70100c:	e5832000 	str	r2, [r3]
  701010:	e51b3010 	ldr	r3, [fp, #-16]
  701014:	e51b2014 	ldr	r2, [fp, #-20]	; 0xffffffec
  701018:	e5832004 	str	r2, [r3, #4]
  70101c:	e51b3010 	ldr	r3, [fp, #-16]
  701020:	e5932000 	ldr	r2, [r3]
  701024:	e51b3008 	ldr	r3, [fp, #-8]
  701028:	e5933004 	ldr	r3, [r3, #4]
  70102c:	e1520003 	cmp	r2, r3
  701030:	1a000021 	bne	7010bc <obj_free+0x178>
  701034:	e51b3008 	ldr	r3, [fp, #-8]
  701038:	e5933008 	ldr	r3, [r3, #8]
  70103c:	e2832001 	add	r2, r3, #1
  701040:	e51b3008 	ldr	r3, [fp, #-8]
  701044:	e5832008 	str	r2, [r3, #8]
  701048:	e51b3008 	ldr	r3, [fp, #-8]
  70104c:	e5933008 	ldr	r3, [r3, #8]
  701050:	e3530004 	cmp	r3, #4
  701054:	da000018 	ble	7010bc <obj_free+0x178>
  701058:	e51b200c 	ldr	r2, [fp, #-12]
  70105c:	e51b1008 	ldr	r1, [fp, #-8]
  701060:	e51b0010 	ldr	r0, [fp, #-16]
  701064:	ebffff82 	bl	700e74 <slab_free>
  701068:	ea000013 	b	7010bc <obj_free+0x178>
  70106c:	e51b3010 	ldr	r3, [fp, #-16]
  701070:	e50b300c 	str	r3, [fp, #-12]
  701074:	e51b3010 	ldr	r3, [fp, #-16]
  701078:	e5933008 	ldr	r3, [r3, #8]
  70107c:	e50b3010 	str	r3, [fp, #-16]
  701080:	e51b3010 	ldr	r3, [fp, #-16]
  701084:	e3530000 	cmp	r3, #0
  701088:	1affffd1 	bne	700fd4 <obj_free+0x90>
  70108c:	e51b3008 	ldr	r3, [fp, #-8]
  701090:	e593300c 	ldr	r3, [r3, #12]
  701094:	e50b3008 	str	r3, [fp, #-8]
  701098:	e51b3008 	ldr	r3, [fp, #-8]
  70109c:	e3530000 	cmp	r3, #0
  7010a0:	1affffb3 	bne	700f74 <obj_free+0x30>
  7010a4:	e59f3028 	ldr	r3, [pc, #40]	; 7010d4 <obj_free+0x190>
  7010a8:	e08f3003 	add	r3, pc, r3
  7010ac:	e1a00003 	mov	r0, r3
  7010b0:	eb000060 	bl	701238 <uart_spin_puts>
  7010b4:	ebfffedb 	bl	700c28 <fail>
  7010b8:	ea000000 	b	7010c0 <obj_free+0x17c>
  7010bc:	e1a00000 	nop			; (mov r0, r0)
  7010c0:	e24bd004 	sub	sp, fp, #4
  7010c4:	e8bd8800 	pop	{fp, pc}
  7010c8:	fffff09c 	.word	0xfffff09c
  7010cc:	00000008 	.word	0x00000008
  7010d0:	0000055c 	.word	0x0000055c
  7010d4:	00000494 	.word	0x00000494

007010d8 <obj_alloc>:
  7010d8:	e92d4800 	push	{fp, lr}
  7010dc:	e28db004 	add	fp, sp, #4
  7010e0:	e24dd018 	sub	sp, sp, #24
  7010e4:	e50b0018 	str	r0, [fp, #-24]	; 0xffffffe8
  7010e8:	e59f213c 	ldr	r2, [pc, #316]	; 70122c <obj_alloc+0x154>
  7010ec:	e08f2002 	add	r2, pc, r2
  7010f0:	e59f3138 	ldr	r3, [pc, #312]	; 701230 <obj_alloc+0x158>
  7010f4:	e7923003 	ldr	r3, [r2, r3]
  7010f8:	e5933000 	ldr	r3, [r3]
  7010fc:	e50b3008 	str	r3, [fp, #-8]
  701100:	ea00003e 	b	701200 <obj_alloc+0x128>
  701104:	e51b3008 	ldr	r3, [fp, #-8]
  701108:	e5932000 	ldr	r2, [r3]
  70110c:	e51b3018 	ldr	r3, [fp, #-24]	; 0xffffffe8
  701110:	e1520003 	cmp	r2, r3
  701114:	da000036 	ble	7011f4 <obj_alloc+0x11c>
  701118:	e51b3008 	ldr	r3, [fp, #-8]
  70111c:	e5933010 	ldr	r3, [r3, #16]
  701120:	e50b300c 	str	r3, [fp, #-12]
  701124:	e51b300c 	ldr	r3, [fp, #-12]
  701128:	e3530000 	cmp	r3, #0
  70112c:	1a00000f 	bne	701170 <obj_alloc+0x98>
  701130:	e3a00001 	mov	r0, #1
  701134:	ebfffd8a 	bl	700764 <alloc_pages>
  701138:	e50b000c 	str	r0, [fp, #-12]
  70113c:	e51b3008 	ldr	r3, [fp, #-8]
  701140:	e5932010 	ldr	r2, [r3, #16]
  701144:	e51b300c 	ldr	r3, [fp, #-12]
  701148:	e5832008 	str	r2, [r3, #8]
  70114c:	e51b3008 	ldr	r3, [fp, #-8]
  701150:	e51b200c 	ldr	r2, [fp, #-12]
  701154:	e5832010 	str	r2, [r3, #16]
  701158:	e51b000c 	ldr	r0, [fp, #-12]
  70115c:	e51b3008 	ldr	r3, [fp, #-8]
  701160:	e5933000 	ldr	r3, [r3]
  701164:	e1a02003 	mov	r2, r3
  701168:	e3a01001 	mov	r1, #1
  70116c:	ebfffeb0 	bl	700c34 <slab_init>
  701170:	e51b300c 	ldr	r3, [fp, #-12]
  701174:	e5933000 	ldr	r3, [r3]
  701178:	e3530000 	cmp	r3, #0
  70117c:	da000018 	ble	7011e4 <obj_alloc+0x10c>
  701180:	e51b300c 	ldr	r3, [fp, #-12]
  701184:	e5933004 	ldr	r3, [r3, #4]
  701188:	e50b3010 	str	r3, [fp, #-16]
  70118c:	e51b3010 	ldr	r3, [fp, #-16]
  701190:	e5932000 	ldr	r2, [r3]
  701194:	e51b300c 	ldr	r3, [fp, #-12]
  701198:	e5832004 	str	r2, [r3, #4]
  70119c:	e51b300c 	ldr	r3, [fp, #-12]
  7011a0:	e5932000 	ldr	r2, [r3]
  7011a4:	e51b3008 	ldr	r3, [fp, #-8]
  7011a8:	e5933004 	ldr	r3, [r3, #4]
  7011ac:	e1520003 	cmp	r2, r3
  7011b0:	1a000004 	bne	7011c8 <obj_alloc+0xf0>
  7011b4:	e51b3008 	ldr	r3, [fp, #-8]
  7011b8:	e5933008 	ldr	r3, [r3, #8]
  7011bc:	e2432001 	sub	r2, r3, #1
  7011c0:	e51b3008 	ldr	r3, [fp, #-8]
  7011c4:	e5832008 	str	r2, [r3, #8]
  7011c8:	e51b300c 	ldr	r3, [fp, #-12]
  7011cc:	e5933000 	ldr	r3, [r3]
  7011d0:	e2432001 	sub	r2, r3, #1
  7011d4:	e51b300c 	ldr	r3, [fp, #-12]
  7011d8:	e5832000 	str	r2, [r3]
  7011dc:	e51b3010 	ldr	r3, [fp, #-16]
  7011e0:	ea00000e 	b	701220 <obj_alloc+0x148>
  7011e4:	e51b300c 	ldr	r3, [fp, #-12]
  7011e8:	e5933008 	ldr	r3, [r3, #8]
  7011ec:	e50b300c 	str	r3, [fp, #-12]
  7011f0:	eaffffcb 	b	701124 <obj_alloc+0x4c>
  7011f4:	e51b3008 	ldr	r3, [fp, #-8]
  7011f8:	e593300c 	ldr	r3, [r3, #12]
  7011fc:	e50b3008 	str	r3, [fp, #-8]
  701200:	e51b3008 	ldr	r3, [fp, #-8]
  701204:	e3530000 	cmp	r3, #0
  701208:	1affffbd 	bne	701104 <obj_alloc+0x2c>
  70120c:	e59f3020 	ldr	r3, [pc, #32]	; 701234 <obj_alloc+0x15c>
  701210:	e08f3003 	add	r3, pc, r3
  701214:	e1a00003 	mov	r0, r3
  701218:	eb000006 	bl	701238 <uart_spin_puts>
  70121c:	ebfffe81 	bl	700c28 <fail>
  701220:	e1a00003 	mov	r0, r3
  701224:	e24bd004 	sub	sp, fp, #4
  701228:	e8bd8800 	pop	{fp, pc}
  70122c:	ffffef0c 	.word	0xffffef0c
  701230:	00000008 	.word	0x00000008
  701234:	0000034c 	.word	0x0000034c

00701238 <uart_spin_puts>:
  701238:	e92d4010 	push	{r4, lr}
  70123c:	e1a04000 	mov	r4, r0
  701240:	e5d00000 	ldrb	r0, [r0]
  701244:	e3500000 	cmp	r0, #0
  701248:	08bd8010 	popeq	{r4, pc}
  70124c:	eb00002d 	bl	701308 <uart_spin_putbyte>
  701250:	e5f40001 	ldrb	r0, [r4, #1]!
  701254:	e3500000 	cmp	r0, #0
  701258:	1afffffb 	bne	70124c <uart_spin_puts+0x14>
  70125c:	e8bd8010 	pop	{r4, pc}

00701260 <uart_enable>:
  701260:	e3a03a01 	mov	r3, #4096	; 0x1000
  701264:	e3a02014 	mov	r2, #20
  701268:	e34e3000 	movt	r3, #57344	; 0xe000
  70126c:	e5832000 	str	r2, [r3]
  701270:	e12fff1e 	bx	lr

00701274 <uart_disable>:
  701274:	e3a03a01 	mov	r3, #4096	; 0x1000
  701278:	e3a02028 	mov	r2, #40	; 0x28
  70127c:	e34e3000 	movt	r3, #57344	; 0xe000
  701280:	e5832000 	str	r2, [r3]
  701284:	e12fff1e 	bx	lr

00701288 <uart_init>:
  701288:	e92d4070 	push	{r4, r5, r6, lr}
  70128c:	e3a04a01 	mov	r4, #4096	; 0x1000
  701290:	e34e4000 	movt	r4, #57344	; 0xe000
  701294:	e3015fff 	movw	r5, #8191	; 0x1fff
  701298:	e584500c 	str	r5, [r4, #12]
  70129c:	ebfffff4 	bl	701274 <uart_disable>
  7012a0:	e3a03020 	mov	r3, #32
  7012a4:	e3a02003 	mov	r2, #3
  7012a8:	e3a0c000 	mov	ip, #0
  7012ac:	e5842000 	str	r2, [r4]
  7012b0:	e3a0003e 	mov	r0, #62	; 0x3e
  7012b4:	e5845014 	str	r5, [r4, #20]
  7012b8:	e3a01006 	mov	r1, #6
  7012bc:	e5843004 	str	r3, [r4, #4]
  7012c0:	e3a02f4a 	mov	r2, #296	; 0x128
  7012c4:	e5843020 	str	r3, [r4, #32]
  7012c8:	e5843044 	str	r3, [r4, #68]	; 0x44
  7012cc:	e584c01c 	str	ip, [r4, #28]
  7012d0:	e5840018 	str	r0, [r4, #24]
  7012d4:	e5841034 	str	r1, [r4, #52]	; 0x34
  7012d8:	e5842000 	str	r2, [r4]
  7012dc:	e8bd8070 	pop	{r4, r5, r6, pc}

007012e0 <uart_spin_getbyte>:
  7012e0:	e3a01a01 	mov	r1, #4096	; 0x1000
  7012e4:	e34e1000 	movt	r1, #57344	; 0xe000
  7012e8:	e591202c 	ldr	r2, [r1, #44]	; 0x2c
  7012ec:	e3a03a01 	mov	r3, #4096	; 0x1000
  7012f0:	e34e3000 	movt	r3, #57344	; 0xe000
  7012f4:	e3120002 	tst	r2, #2
  7012f8:	1afffffa 	bne	7012e8 <uart_spin_getbyte+0x8>
  7012fc:	e5930030 	ldr	r0, [r3, #48]	; 0x30
  701300:	e6ef0070 	uxtb	r0, r0
  701304:	e12fff1e 	bx	lr

00701308 <uart_spin_putbyte>:
  701308:	e3a01a01 	mov	r1, #4096	; 0x1000
  70130c:	e34e1000 	movt	r1, #57344	; 0xe000
  701310:	e591202c 	ldr	r2, [r1, #44]	; 0x2c
  701314:	e3a03a01 	mov	r3, #4096	; 0x1000
  701318:	e34e3000 	movt	r3, #57344	; 0xe000
  70131c:	e3120010 	tst	r2, #16
  701320:	1afffffa 	bne	701310 <uart_spin_putbyte+0x8>
  701324:	e5830030 	str	r0, [r3, #48]	; 0x30
  701328:	e12fff1e 	bx	lr

0070132c <puthex>:
  70132c:	e92d4800 	push	{fp, lr}
  701330:	e28db004 	add	fp, sp, #4
  701334:	e24dd030 	sub	sp, sp, #48	; 0x30
  701338:	e50b0030 	str	r0, [fp, #-48]	; 0xffffffd0
  70133c:	e59f30ac 	ldr	r3, [pc, #172]	; 7013f0 <puthex+0xc4>
  701340:	e08f3003 	add	r3, pc, r3
  701344:	e24bc01c 	sub	ip, fp, #28
  701348:	e1a0e003 	mov	lr, r3
  70134c:	e8be000f 	ldm	lr!, {r0, r1, r2, r3}
  701350:	e8ac000f 	stmia	ip!, {r0, r1, r2, r3}
  701354:	e59e3000 	ldr	r3, [lr]
  701358:	e5cc3000 	strb	r3, [ip]
  70135c:	e59f2090 	ldr	r2, [pc, #144]	; 7013f4 <puthex+0xc8>
  701360:	e08f2002 	add	r2, pc, r2
  701364:	e24b3028 	sub	r3, fp, #40	; 0x28
  701368:	e8920007 	ldm	r2, {r0, r1, r2}
  70136c:	e8a30003 	stmia	r3!, {r0, r1}
  701370:	e1c320b0 	strh	r2, [r3]
  701374:	e2833002 	add	r3, r3, #2
  701378:	e1a02822 	lsr	r2, r2, #16
  70137c:	e5c32000 	strb	r2, [r3]
  701380:	e3a0301c 	mov	r3, #28
  701384:	e50b3008 	str	r3, [fp, #-8]
  701388:	ea00000f 	b	7013cc <puthex+0xa0>
  70138c:	e51b3008 	ldr	r3, [fp, #-8]
  701390:	e263301c 	rsb	r3, r3, #28
  701394:	e1a03143 	asr	r3, r3, #2
  701398:	e51b1030 	ldr	r1, [fp, #-48]	; 0xffffffd0
  70139c:	e51b2008 	ldr	r2, [fp, #-8]
  7013a0:	e1a02231 	lsr	r2, r1, r2
  7013a4:	e202200f 	and	r2, r2, #15
  7013a8:	e24b1004 	sub	r1, fp, #4
  7013ac:	e0812002 	add	r2, r1, r2
  7013b0:	e5522018 	ldrb	r2, [r2, #-24]	; 0xffffffe8
  7013b4:	e24b1004 	sub	r1, fp, #4
  7013b8:	e0813003 	add	r3, r1, r3
  7013bc:	e5432024 	strb	r2, [r3, #-36]	; 0xffffffdc
  7013c0:	e51b3008 	ldr	r3, [fp, #-8]
  7013c4:	e2433004 	sub	r3, r3, #4
  7013c8:	e50b3008 	str	r3, [fp, #-8]
  7013cc:	e51b3008 	ldr	r3, [fp, #-8]
  7013d0:	e3530000 	cmp	r3, #0
  7013d4:	aaffffec 	bge	70138c <puthex+0x60>
  7013d8:	e24b3028 	sub	r3, fp, #40	; 0x28
  7013dc:	e1a00003 	mov	r0, r3
  7013e0:	ebffff94 	bl	701238 <uart_spin_puts>
  7013e4:	e1a00000 	nop			; (mov r0, r0)
  7013e8:	e24bd004 	sub	sp, fp, #4
  7013ec:	e8bd8800 	pop	{fp, pc}
  7013f0:	0000023c 	.word	0x0000023c
  7013f4:	00000230 	.word	0x00000230
