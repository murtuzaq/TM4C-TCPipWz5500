/*
 * wizDriver.h
 *
 *  Created on: Sep 7, 2016
 *      Author: mquaizar
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WIZ5500_WIZDRIVER_H_
#define WIZ5500_WIZDRIVER_H_


extern void IINCHIP_CSoff(void);
extern void IINCHIP_CSon(void);
extern uint8_t  IINCHIP_SpiSendData(uint8_t dat);
extern void IINCHIP_SPI_Init(void);
extern void IINCHIP_CS_Init(void);
void IINCHIP_Delay_ms(uint16_t);

#endif /* WIZ5500_WIZDRIVER_H_ */


#ifdef __cplusplus
}
#endif

