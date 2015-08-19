/*
 * Copyright (C) 2015 Gan Quan <coin2028@hotmail.com>
 *
 * This program is free software; you can redistribute  it and/or modify it
 * under  the terms of  the GNU General  Public License as published by the
 * Free Software Foundation;  either version 2 of the  License, or (at your
 * option) any later version.
 *
 */

void main(void)
{
	/*
	 * Startup routine.
	 * Somehow combined the one in xv6 with that in Linux.
	 * @davidgao @leon001 please review
	 * 0.  Hardware probing etc.
	 * 1.  Trap
	 * 2.  SMP per-CPU setup
	 * 3.  Interrupt, including PIC, LAPIC, IOAPIC etc.
	 * 4.  Disk storage
	 * 5.  Memory mapping, including page tables, allocators etc.
	 *     a)  Swapping
	 * 6.  Scheduler
	 * 7.  File system
	 * 8.  SMP Startup
	 *     a)  Slave CPUs should skip to step 11
	 * 9.  Fork and load /sbin/init into process table
	 * 10. Enable swapping & scheduler
	 * 11. Enter idle stage
	 */
	local_irq_disable();

	trap_init();

	smp_setup();

	init_irq();

	disk_init();

	mm_init();

	sched_init();

	fs_init();

	smp_startup();

	userinit_init();

	swap_enable();

	/* Enable all interrupts including timer, thus enabling scheduler */
	local_irq_enable();

	/* We're now alive! */
	cpu_idle();
}