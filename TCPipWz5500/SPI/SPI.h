#ifndef _SPI_H_
#define _SPI_H_

typedef enum {
	SPI_CS_HIGH,
	SPI_CS_LOW
} SPI_CS_DIR;

extern void SPI_Init(void);
extern void SPI_CS_Init(void);
extern unsigned char spiRdWt(unsigned char data);
extern void SPI_CS(SPI_CS_DIR dir);



#endif
