/*
 * w5500Reg.h
 *
 *  Created on: Sep 13, 2016
 *      Author: mquaizar
 */

#ifndef ETHERNET_UTILITY_W5500REG_H_
#define ETHERNET_UTILITY_W5500REG_H_

#include <stdint.h>

typedef struct {
	uint8_t MR;		//Mode
	uint8_t GAR0; 	//GatewayAddress
	uint8_t GAR1;
	uint8_t GAR2;
	uint8_t GAR3;
	uint8_t SUBR0;	//SubNet Mask Address
	uint8_t SUBR1;
	uint8_t SUBR2;
	uint8_t SUBR3;
	uint8_t SHAR0; //MAC Address
	uint8_t SHAR1;
	uint8_t SHAR2;
	uint8_t SHAR3;
	uint8_t SHAR4;
	uint8_t SHAR5;
	uint8_t SIPR0;	//source IP Addrress;
	uint8_t SIPR1;
	uint8_t SIPR2;
	uint8_t SIPR3;
	uint8_t INTLEVEL0;
	uint8_t INTLEVEL1;
	uint8_t IR;
	uint8_t IMR;
	uint8_t SIR;
	uint8_t SIMR;
	uint8_t RTRO;
	uint8_t RTR1;
	uint8_t RCR;
	uint8_t PTIMER;
	uint8_t PMAGIC;
	uint8_t PHAR0;
	uint8_t PHAR1;
	uint8_t PHAR2;
	uint8_t PHAR3;
	uint8_t PHAR4;
	uint8_t PHAR5;
	uint8_t PSID0;
	uint8_t PSID1;
	uint8_t PMRU0;
	uint8_t PMRU1;
	uint8_t UIPR0;
	uint8_t UIPR1;
	uint8_t UIPR2;
	uint8_t UIPR3;
	uint8_t UPORTR0;
	uint8_t UPORTR1;
	uint8_t PHYCFGR;
	uint8_t RESERVED_2F;
	uint8_t RESERVED_30;
	uint8_t RESERVED_31;
	uint8_t RESERVED_32;
	uint8_t RESERVED_33;
	uint8_t RESERVED_34;
	uint8_t RESERVED_35;
	uint8_t RESERVED_36;
	uint8_t RESERVED_37;
	uint8_t RESERVED_38;
	uint8_t VERSIONR;

} w5500RegCmn;


typedef struct {
	uint8_t Sn_MR;		//Mode
	uint8_t Sn_CR; 	//GatewayAddress
	uint8_t Sn_IR;
	uint8_t Sn_SR;
	uint8_t Sn_PORT0;
	uint8_t Sn_PORT1;	//SubNet Mask Address
	uint8_t Sn_DHAR0;
	uint8_t Sn_DHAR1;
	uint8_t Sn_DHAR2;
	uint8_t Sn_DHAR3; //MAC Address
	uint8_t Sn_DHAR4;
	uint8_t Sn_DHAR5;
	uint8_t Sn_DIPR0;
	uint8_t Sn_DIPR1;
	uint8_t Sn_DIPR2;
	uint8_t Sn_DIPR3;	//source IP Addrress;
	uint8_t Sn_DPORT0;
	uint8_t Sn_DPORT1;
	uint8_t Sn_MSSR0;
	uint8_t Sn_MSSR1;
	uint8_t RESERVED_14;
	uint8_t Sn_TOS;
	uint8_t Sn_TTL;
	uint8_t RESERVED_17;
	uint8_t RESERVED_18;
	uint8_t RESERVED_19;
	uint8_t RESERVED_1A;
	uint8_t RESERVED_1B;
	uint8_t RESERVED_1C;
	uint8_t RESERVED_1D;
	uint8_t Sn_RXBUF_SIZE;
	uint8_t Sn_TXBUF_SIZE;
	uint8_t Sn_TX_FSR0;
	uint8_t Sn_TX_FSR1;
	uint8_t Sn_TX_RD0;
	uint8_t Sn_TX_RD1;
	uint8_t Sn_TX_WR0;
	uint8_t Sn_TX_WR1;
	uint8_t Sn_RX_RSR0;
	uint8_t Sn_RX_RSR1;
	uint8_t Sn_RX_RD0;
	uint8_t Sn_RX_RD1;
	uint8_t Sn_RX_WR0;
	uint8_t Sn_RX_WR1;
	uint8_t Sn_IMR;
	uint8_t Sn_FRAG0;
	uint8_t Sn_FRAG1;
	uint8_t Sn_KPALVTR;
	uint8_t RESERVED_30;
	uint8_t RESERVED_31;
	uint8_t RESERVED_32;
	uint8_t RESERVED_33;
	uint8_t RESERVED_34;
	uint8_t RESERVED_35;
	uint8_t RESERVED_36;
	uint8_t RESERVED_37;
	uint8_t RESERVED_38;
	uint8_t RESERVED_39;

} w5500RegSkt;

#endif /* ETHERNET_UTILITY_W5500REG_H_ */
