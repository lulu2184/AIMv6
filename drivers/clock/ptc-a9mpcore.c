#include "ptc-a9mpcore.h"
#include <asm/io.h>

u32 ptc_get_time() {
	u32 tmp = in32(PTC_BASE + PTC_COUNTER_OFFSET);
	return tmp;
}

void ptc_set_load_time(u32 time) {
	out32(PTC_BASE + PTC_LOAD_OFFSET, time);
}

void ptc_init(u32 time_interval) {
	u32 reg_value = in32(PTC_BASE + PTC_CONTROL_OFFSET);
	//enable IRQ
	reg_value = (reg_value | 4);
	//auto reload
	reg_value = (reg_value | 2);

	//set interval
	ptc_set_load_time(time_interval);
	out32(PTC_BASE + PTC_CONTROL_OFFSET, reg_value);
}

void ptc_enable() {
	// out32(PTC_BASE + PTC_COUNTER_OFFSET, TIME_INTERVAL);

	u32 reg_value;
	reg_value = in32(PTC_BASE + PTC_CONTROL_OFFSET);
	//enable
	reg_value = (reg_value | 1);
	out32(PTC_BASE + PTC_CONTROL_OFFSET, reg_value);
}
