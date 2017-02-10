/*
 * wizDriver.c
 *
 *  Created on: Sep 7, 2016
 *      Author: mquaizar
 */
#include <stdint.h>
#include "../../SPI/SPI.h"


void IINCHIP_CSoff(void)
{
  //WIZ_CS(LOW);
  //WIZ_CS2(LOW);
  //wizspi_cs(WIZ_SPI2, VAL_LOW);
  //wizspi_cs(WIZ_SPI1, VAL_LOW);

  //WIZ_SCS_PORT &= ~WIZ_SCS_PIN;

  SPI_CS(SPI_CS_LOW);
}
void IINCHIP_CSon(void)
{
  //WIZ_CS(HIGH);
  //WIZ_CS2(HIGH);
  //wizspi_cs(WIZ_SPI2, VAL_HIGH);
  //wizspi_cs(WIZ_SPI1, VAL_HIGH);

  //WIZ_SCS_PORT |= WIZ_SCS_PIN;

	SPI_CS(SPI_CS_HIGH);
}
uint8_t  IINCHIP_SpiSendData(uint8_t dat)
{
  //return(SPI1_SendByte(dat));
  //return(SPI2_SendByte(dat));
  //return(wizspi_byte(WIZ_SPI2, dat));
  //return(wizspi_byte(WIZ_SPI1, dat));

  //return MSP430_SpiSendData(dat);

	return(spiRdWt(dat));
}

void IINCHIP_SPI_Init(void)
{
	SPI_Init();
}

void IINCHIP_CS_Init(void)
{
	SPI_CS_Init();
}

void IINCHIP_Delay_ms(uint16_t ms)
{
#define CLOCK_MHZ 16

	uint32_t i,j;
	for (i = 0; i < ms; i++)
	{
		for(j = 0; j < CLOCK_MHZ * 1000;j++){}
	}
}


