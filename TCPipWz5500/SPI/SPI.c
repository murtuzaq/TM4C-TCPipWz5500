#include "../tm4c123gh6pm.h"
#include "SPI.h"

void ConfigureSPI_SS2(void)
{
  //15.4 Configure SSI Module 2 (spi2), Pins: PB4,PB6,PB7
  //--------------------------------------------------------------
  //1. Enable the SSI module using the RCGCSSI register
  SYSCTL_RCGCSSI_R |= 0x04;  //Enable Run Mode Clock to SSI Module 2
  //2. Enable the clock to the GPIO module via the RCGCGPIO register
  SYSCTL_RCGCGPIO_R |= 0x02; //Enable GPIO Port B;
  //3. Set the GPIO AFSEL bits for the appropriate pins 
  GPIO_PORTB_AFSEL_R |=0x10;  //PB4 (CLK)
  GPIO_PORTB_AFSEL_R |=0x40;  //PB6 (MISO)
  GPIO_PORTB_AFSEL_R |=0x80;  //PB7 (MOSI)
  //4. Configure the PMCn fields in the GPIOPCTL register to SSI signals
  GPIO_PORTB_PCTL_R &= ~(0xF <<16U); //Clear bits
  GPIO_PORTB_PCTL_R |= (2 <<16U); //PB4 //SPI_CLK
  GPIO_PORTB_PCTL_R &= ~(0xF <<24U); //Clear bits
  GPIO_PORTB_PCTL_R |= (2 <<24U); //PB6 //SPI_RX
  GPIO_PORTB_PCTL_R &= ~(0xF <<28U); //Clear bits
  GPIO_PORTB_PCTL_R |= (2 <<28U); //PB7 //SPI_TX
 //5. Program the GPIODEN register to enable the pin's digital function. 
 //   Configure, the drive strength, drain select and pull-up/pull-down 
  GPIO_PORTB_DEN_R |=0x10;  //PB4
  GPIO_PORTB_DEN_R |=0x40;  //PB6
  GPIO_PORTB_DEN_R |=0x80;  //PB7
  
  GPIO_PORTB_PUR_R |=0x10; //pull up on CLK.
  
 //1. Clear SSE bit in the SSICR1 register before making any changes.
  SSI2_CR1_R &= ~(0x02);
 //2. Select whether the SSI is a master or slave:
  SSI2_CR1_R = 0x00000000;  //configure SS1 as master mode;
 //3. Configure the SSI clock source by writing to the SSICC register.
  SSI2_CC_R &= ~(0x0F);//System Clock based on clock source and divisior factor
 //4. Configure the clock prescale divisor by writing the SSICPSR register.
 //SSInCLK = SysClk/(CPSDVSR *(1+SCR)) //SPI Clk Speed - (16Mhz/(4*1))= 4Mhz
  SSI2_CPSR_R = 4;  //Divde by 4;  //Set the CPSDVSR
 //5. Write the SSICR0 register with the following configuration:
 //¦ Serial clock rate (SCR)
  SSI2_CR0_R &= ~(0xFF << 8U); //Clear data bits;
  SSI2_CR0_R |= (0x00 << 8U); // SCR = 0;
 //¦ Desired clock phase/polarity, if using Freescale SPI mode (SPH and SPO)
  SSI2_CR0_R &= ~(0x1 << 7U);  //Data is captured on the first clock edge
 //¦ The protocol mode: Freescale SPI, TI SSF, MICROWIRE (FRF)
  SSI2_CR0_R &= ~(0x3 << 4U); //Clear data bits;
  SSI2_CR0_R |= (0x0 << 4U); //Select Freescale SPI Frame Format
 //¦ The data size (DSS)
  SSI2_CR0_R |= (0x7 << 0U); //8 - Bit data;
  
  
 //7. Enable the SSI by setting the SSE bit in the SSICR1 register.
  SSI2_CR1_R |= 0x02; //ENABLE SSI;
}

void Configure_PA5_DOUT(void)  //SPI CS
{
  SYSCTL_RCGCGPIO_R |= (1 << 0U);  //Enable Clock for PORT A
  
  GPIO_PORTA_DIR_R |= (1 <<5U);         // Enable Bit 5 on PORT A (SPI CS)
  
  GPIO_PORTA_LOCK_R = 0x4C4F434B;       //unlock code on PORT A;
  GPIO_PORTA_PCTL_R &= ~(0xFF <<20U);   //Overwrite Control on PA5 to GPIO
  GPIO_PORTA_LOCK_R = 0; //relock.      //lock code on PORT A;
  
  GPIO_PORTA_DEN_R |= (1 <<5U);         //Enable Bit 5 on PORT A as DIGITAL IO
}


unsigned char spiRdWt(unsigned char data)
{
  
   unsigned int ui32RcvDat;
    
   //Wait for Transmit buffer to empty
    while((SSI2_SR_R & 0x02) == 0){}
    SSI2_DR_R  = data;
    
   //wait for Receive buffer to fill up
    while((SSI2_SR_R & 0x04) == 0){}
    ui32RcvDat = SSI2_DR_R;
    
    return((unsigned char)ui32RcvDat);
    
}

void SPI_Init(void)
{
	ConfigureSPI_SS2();
	Configure_PA5_DOUT();
}

void SPI_CS_Init(void)
{
	Configure_PA5_DOUT();
}

void SPI_CS(SPI_CS_DIR dir)
{
	if (dir == SPI_CS_HIGH)
	{
		 GPIO_PORTA_DATA_R |= (1 <<5U);
	}
	else if (dir == SPI_CS_LOW)
	{
		GPIO_PORTA_DATA_R &= ~(1 <<5U);
	}
}







