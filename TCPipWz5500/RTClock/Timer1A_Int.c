#include "../tm4c123gh6pm.h"

extern void Timer1_Callback(void);

void Configure_Timer_1_A_INT(void)
{
	  //11.4 TIMERS (Timer1 A)
	  SYSCTL_RCGCTIMER_R |= 0x02;
	  //11.4.1 One/Shot Periodic Timer Mode
	  //1) Clear the TnEN bit in the GPTMCTL register
	  TIMER1_CTL_R &=  ~(0x01);
	  //2) Write the GPTMCFG Configuration Register with a value of 0x0000.0000.
	  TIMER1_CFG_R  = 0x00000000;
	  /*3 Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR):
	      a. Write a value of 0x1 for One-Shot mode.
	      b. Write a value of 0x2 for Periodic mode
	  */
	  TIMER1_TAMR_R = 0x02;
	  //4 -----skip----
	  //5 Load the start value into the GPTM Timer n Interval GPTMTnILR)
	  TIMER1_TAILR_R = 16000; // //1ms Resolution;
	  //6 For interrupts, set bits in the GPTM Interrupt Mask Register (GPTMIMR)
	  TIMER1_IMR_R |= (0x1<<0U); //Enable Timer A Time-Out Interrupt
	  NVIC_EN0_R |= (0x1 <<21U);  //Enable Nested Vector Interrupt Control for ISR
	  //7 Set the TnEN bit in GPTMCTL to enable the timer and start counting.

	  TIMER1_CTL_R |=  (0x01);
}



void Timer1A_Interrupt(void)
{
	if((TIMER1_RIS_R & 0x01) == 0x01)
	{
		TIMER1_ICR_R |= 0x01; //clear Timer A Time Out.
	}
	
	Timer1_Callback();
}





