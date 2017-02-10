/*
  main.cpp - Main loop for Arduino sketches
  Copyright (c) 2005-2013 Arduino Team.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "Arduino.h"
#include "RTClock/RTClock.h"
#include "Ethernet/Ethernet.h"
#include "Ethernet/utility/w5500.h"
#include "Ethernet/utility/w5500Reg.h"

//Declared weak in Arduino.h to allow user redefinitions.
int atexit(void (*func)()) { return 0; }

// Weak empty variant initialization function.
// May be redefined by variant files.
void initVariant() __attribute__((weak));
void initVariant() { }

byte mac[] = {0x00, 0x08, 0xDC, 0x1F, 0xD1, 0xE0};
IPAddress ip(205,1,6,110);//(192,168,0,177);
IPAddress dns_server(205,1,6,10);//(192,168,0,1);
IPAddress gateway(205,1,6,10);//(192,168,0,1);
IPAddress subnet(255,255,255,0);

w5500RegCmn w5500Cmn;
w5500RegSkt w5500Skt[8];


// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);

void Readw5500CmnReg(void);
void Readw5500SktReg(uint8_t);

void main(void)
{

	init();

	initVariant();
	
	setup();
    
	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
        
}

void init(void)
{

}


// the setup function runs once when you press reset or power the board
void setup() {

	Timer_ms_Init();
	//Ethernet.begin(mac, ip);


	Ethernet.begin(mac, ip, dns_server, gateway, subnet);

	server.begin();

	Readw5500CmnReg();
	Readw5500SktReg(0);
	Readw5500SktReg(1);
	Readw5500SktReg(2);
	Readw5500SktReg(3);
	Readw5500SktReg(4);
	Readw5500SktReg(5);
	Readw5500SktReg(6);
	Readw5500SktReg(7);

}

// the loop function runs over and over again forever
void loop() {

	 // listen for incoming clients
	  EthernetClient client = server.available();

		Readw5500CmnReg();
		Readw5500SktReg(0);
		Readw5500SktReg(1);
		Readw5500SktReg(2);
		Readw5500SktReg(3);
		Readw5500SktReg(4);
		Readw5500SktReg(5);
		Readw5500SktReg(6);
		Readw5500SktReg(7);

	  if (client) {
	    //Serial.println("new client");
	    // an http request ends with a blank line
	    boolean currentLineIsBlank = true;
	    while (client.connected()) {
	      if (client.available()) {
	        char c = client.read();
	        //Serial.write(c);
	        // if you've gotten to the end of the line (received a newline
	        // character) and the line is blank, the http request has ended,
	        // so you can send a reply
	        if (c == '\n' && currentLineIsBlank) {
	          // send a standard http response header
	          client.println("HTTP/1.1 200 OK");
	          client.println("Content-Type: text/html");
	          client.println("Connection: close");  // the connection will be closed after completion of the response
	          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
	          client.println();
	          client.println("<!DOCTYPE HTML>");
	          client.println("<html>");
	          // output the value of each analog input pin

	            //int sensorReading = analogRead(analogChannel);
	            client.print("MURTUZA QUAIZAR SAYS HELLO FROM TIVA");
	            client.println("<br />");

	            client.print("TIME ALIVE IS: ");
	            client.print(millis());

	            client.println("<br />");

	          client.println("</html>");
	          break;
	        }
	        if (c == '\n') {
	          // you're starting a new line
	          currentLineIsBlank = true;
	        }
	        else if (c != '\r') {
	          // you've gotten a character on the current line
	          currentLineIsBlank = false;
	        }
	      }
	    }
	    // give the web browser time to receive the data
	    IINCHIP_Delay_ms(1);
	    // close the connection:
	    client.stop();
	    //Serial.println("client disonnected");
	  }

}

void Readw5500CmnReg(void)
{
	w5500Cmn.MR = 	W5100.read(0x00, 0x00);
	w5500Cmn.GAR0 = W5100.read(0x01, 0x00);
	w5500Cmn.GAR1 = W5100.read(0x02, 0x00);
	w5500Cmn.GAR2 = W5100.read(0x03, 0x00);
	w5500Cmn.GAR3 = W5100.read(0x04, 0x00);
	w5500Cmn.SUBR0 = W5100.read(0x05, 0x00);
	w5500Cmn.SUBR1 = W5100.read(0x06, 0x00);
	w5500Cmn.SUBR2 = W5100.read(0x07, 0x00);
	w5500Cmn.SUBR3 = W5100.read(0x08, 0x00);
	w5500Cmn.SHAR0 = W5100.read(0x09, 0x00); //MAC Address
	w5500Cmn.SHAR1 = W5100.read(0x0A, 0x00);
	w5500Cmn.SHAR2 = W5100.read(0x0B, 0x00);
	w5500Cmn.SHAR3 = W5100.read(0x0C, 0x00);
	w5500Cmn.SHAR4 = W5100.read(0x0D, 0x00);
	w5500Cmn.SHAR5 = W5100.read(0x0E, 0x00);
	w5500Cmn.SIPR0 = W5100.read(0x0F, 0x00);	//source IP Addrress;
	w5500Cmn.SIPR1 = W5100.read(0x10, 0x00);
	w5500Cmn.SIPR2 = W5100.read(0x11, 0x00);
	w5500Cmn.SIPR3 = W5100.read(0x12, 0x00);
	w5500Cmn.INTLEVEL0 = W5100.read(0x13, 0x00);
	w5500Cmn.INTLEVEL1 = W5100.read(0x14, 0x00);
	w5500Cmn.IR = W5100.read(0x15, 0x00);
	w5500Cmn.IMR = W5100.read(0x16, 0x00);
	w5500Cmn.SIR = W5100.read(0x17, 0x00);
	w5500Cmn.SIMR = W5100.read(0x18, 0x00);
	w5500Cmn.RTRO = W5100.read(0x19, 0x00);
	w5500Cmn.RTR1 = W5100.read(0x1A, 0x00);
	w5500Cmn.RCR = W5100.read(0x1B, 0x00);
	w5500Cmn.PTIMER = W5100.read(0x1C, 0x00);
	w5500Cmn.PMAGIC = W5100.read(0x1D, 0x00);
	w5500Cmn.PHAR0 = W5100.read(0x1E, 0x00);
	w5500Cmn.PHAR1 = W5100.read(0x1F, 0x00);
	w5500Cmn.PHAR2 = W5100.read(0x20, 0x00);
	w5500Cmn.PHAR3 = W5100.read(0x21, 0x00);
	w5500Cmn.PHAR4 = W5100.read(0x22, 0x00);
	w5500Cmn.PHAR5 = W5100.read(0x23, 0x00);
	w5500Cmn.PSID0 = W5100.read(0x24, 0x00);
	w5500Cmn.PSID1 = W5100.read(0x25, 0x00);
	w5500Cmn.PMRU0 = W5100.read(0x26, 0x00);
	w5500Cmn.PMRU1 = W5100.read(0x27, 0x00);
	w5500Cmn.UIPR0 = W5100.read(0x28, 0x00);
	w5500Cmn.UIPR1 = W5100.read(0x29, 0x00);
	w5500Cmn.UIPR2 = W5100.read(0x2A, 0x00);
	w5500Cmn.UIPR3 = W5100.read(0x2B, 0x00);
	w5500Cmn.UPORTR0 = W5100.read(0x2C, 0x00);
	w5500Cmn.UPORTR1 = W5100.read(0x2D, 0x00);
	w5500Cmn.PHYCFGR = W5100.read(0x2E, 0x00);
	w5500Cmn.RESERVED_2F = 0;
	w5500Cmn.RESERVED_30 = 0;
	w5500Cmn.RESERVED_31 = 0;
	w5500Cmn.RESERVED_32 = 0;
	w5500Cmn.RESERVED_33 = 0;
	w5500Cmn.RESERVED_34 = 0;
	w5500Cmn.RESERVED_35 = 0;
	w5500Cmn.RESERVED_36 = 0;
	w5500Cmn.RESERVED_37 = 0;
	w5500Cmn.RESERVED_38 = 0;
	w5500Cmn.VERSIONR = W5100.read(0x39, 0x00) ;
}

void Readw5500SktReg(uint8_t socket) {
	w5500Skt[socket].Sn_MR = W5100.readSn(socket, 0x00);
	w5500Skt[socket].Sn_CR = W5100.readSn(socket, 0x01);
	w5500Skt[socket].Sn_IR = W5100.readSn(socket, 0x02);
	w5500Skt[socket].Sn_SR = W5100.readSn(socket, 0x03);
	w5500Skt[socket].Sn_PORT0 = W5100.readSn(socket, 0x04);
	w5500Skt[socket].Sn_PORT1 = W5100.readSn(socket, 0x05);
	w5500Skt[socket].Sn_DHAR0 = W5100.readSn(socket, 0x06);
	w5500Skt[socket].Sn_DHAR1 = W5100.readSn(socket, 0x07);
	w5500Skt[socket].Sn_DHAR2 = W5100.readSn(socket, 0x08);
	w5500Skt[socket].Sn_DHAR3 = W5100.readSn(socket, 0x09);
	w5500Skt[socket].Sn_DHAR4 = W5100.readSn(socket, 0x0A);
	w5500Skt[socket].Sn_DHAR5 = W5100.readSn(socket, 0x0B);
	w5500Skt[socket].Sn_DIPR0 = W5100.readSn(socket, 0x0C);
	w5500Skt[socket].Sn_DIPR1 = W5100.readSn(socket, 0x0D);
	w5500Skt[socket].Sn_DIPR2 = W5100.readSn(socket, 0x0E);
	w5500Skt[socket].Sn_DIPR3 = W5100.readSn(socket, 0x0F);
	w5500Skt[socket].Sn_DPORT0 = W5100.readSn(socket, 0x10);
	w5500Skt[socket].Sn_DPORT1 = W5100.readSn(socket, 0x11);
	w5500Skt[socket].Sn_MSSR0 = W5100.readSn(socket, 0x12);
	w5500Skt[socket].Sn_MSSR1 = W5100.readSn(socket, 0x13);
	w5500Skt[socket].RESERVED_14 = 0;
	w5500Skt[socket].Sn_TOS = W5100.readSn(socket, 0x15);
	w5500Skt[socket].Sn_TTL = W5100.readSn(socket, 0x16);
	w5500Skt[socket].RESERVED_17 = 0;
	w5500Skt[socket].RESERVED_18 = 0;
	w5500Skt[socket].RESERVED_19 = 0;
	w5500Skt[socket].RESERVED_1A = 0;
	w5500Skt[socket].RESERVED_1B = 0;
	w5500Skt[socket].RESERVED_1C = 0;
	w5500Skt[socket].RESERVED_1D = 0;
	w5500Skt[socket].Sn_RXBUF_SIZE = W5100.readSn(socket, 0x1E);
	w5500Skt[socket].Sn_TXBUF_SIZE = W5100.readSn(socket, 0x1F);
	w5500Skt[socket].Sn_TX_FSR0 = W5100.readSn(socket, 0x20);
	w5500Skt[socket].Sn_TX_FSR1 = W5100.readSn(socket, 0x21);
	w5500Skt[socket].Sn_TX_RD0 = W5100.readSn(socket, 0x22);
	w5500Skt[socket].Sn_TX_RD1 = W5100.readSn(socket, 0x23);
	w5500Skt[socket].Sn_TX_WR0 = W5100.readSn(socket, 0x24);
	w5500Skt[socket].Sn_TX_WR1 = W5100.readSn(socket, 0x25);
	w5500Skt[socket].Sn_RX_RSR0 = W5100.readSn(socket, 0x26);
	w5500Skt[socket].Sn_RX_RSR1 = W5100.readSn(socket, 0x27);
	w5500Skt[socket].Sn_RX_RD0 = W5100.readSn(socket, 0x28);
	w5500Skt[socket].Sn_RX_RD1 = W5100.readSn(socket, 0x29);
	w5500Skt[socket].Sn_RX_WR0 = W5100.readSn(socket, 0x2A);
	w5500Skt[socket].Sn_RX_WR1 = W5100.readSn(socket, 0x2B);
	w5500Skt[socket].Sn_IMR = W5100.readSn(socket, 0x2C);
	w5500Skt[socket].Sn_FRAG0 = W5100.readSn(socket, 0x2D);
	w5500Skt[socket].Sn_FRAG1 = W5100.readSn(socket, 0x2E);
	w5500Skt[socket].Sn_KPALVTR = W5100.readSn(socket, 0x2F);

}
