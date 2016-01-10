#ifndef _DRIVERS_PTC_A9MPCORE_
#define _DRIVERS_PTC_A9MPCORE_

#include <config.h>

#define PTC_OFFSET 0x600

#define PTC_BASE (MPCORE_PHYSBASE + PTC_OFFSET)

#define PTC_LOAD_OFFSET 0x00
#define PTC_COUNTER_OFFSET 0x04
#define PTC_CONTROL_OFFSET 0x08
#define PTC_INT_STATUS_OFFSET 0x0C

#define TIME_INTERVAL 0x20000

u32 ptc_get_time();
void ptc_load_time(u32 time);
void ptc_init(u32 time_interval);
void ptc_enable();

#endif