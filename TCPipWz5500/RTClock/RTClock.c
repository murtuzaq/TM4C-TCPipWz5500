
#include "Timer1A_Int.h"


unsigned long Tick_ms = 0;


void Timer_ms_Init(void)
{
	Configure_Timer_1_A_INT();
}


void Timer_ms(void)
{
	Tick_ms++;
}

void Timer1_Callback(void)
{
	Timer_ms();
}


unsigned long GetTick_ms(void)
{
	return(Tick_ms);
}

unsigned long millis(void)
{
	return(GetTick_ms());
}


