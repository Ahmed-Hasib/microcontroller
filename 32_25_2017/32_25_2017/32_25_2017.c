/*
 * _32_25_2017.c
 *
 * Created: 8/25/2017 01:12:21 PM
 *  Author: Hasib
 */ 


#include <avr/io.h>
#include <util/delay.h>

#define d_h PORTB |=(1<<PINB0)
#define d_l PORTB &=~(1<<PINB0)

#define cl_h PORTB |=(1<<PINB1)
#define cl_l PORTB &=~(1<<PINB1)

#define cs_h PORTB |=(1<<PINB2)
#define cs_l PORTB &=~(1<<PINB2)

 


 //-------------------------------------------------------------------------------------------------


 void SPI_MasterInit(void)
 {
	 DDRB = (1<<DDB5)|(0<<DDB6)|(1<<DDB7)|(1<<DDB4);
	 SPCR = (1<<SPE)|(1<<MSTR);
 }

 void spi_readwrite(unsigned char value)
 {
	 cl_l;
	 SPDR = value;
	 
	 while(!(SPSR & (1<<SPIF)));
	 cl_h;
 }


 //-------------------------------------------------------------------------------------------------

 int main(void)
 {
	 DDRB |=(1<<PINB0) |(1<<PINB1) |(1<<PINB2);
	 SPI_MasterInit();
	 while(1)
	 {
		 PORTB|=(4<<0);
		//PORTB |=(PINB4);
		cs_l;
		 spi_readwrite(0b11110000);
		 cs_h;
		 //PORTB &=~(PINB4);
		PORTB|=(4<<1);

	 }
 }