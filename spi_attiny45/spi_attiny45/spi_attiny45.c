/*
 * spi_attiny45.c
 *
 * Created: 8/18/2017 01:00:22 AM
 *  Author: Hasib
 */ 


#include <avr/io.h>
#include<util/delay.h>

//
// Initialize SPI Master Device (with SPI interrupt)
void spi_init_master (void)
{
	// Set MOSI, SCK as Output
	DDRB=(1<<5)|(1<<3);
	
	// Enable SPI, Set as Master
	// Prescaler: Fosc/16, Enable Interrupts
	//The MOSI, SCK pins are as per ATMega8
	SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPIE);
	
	// Enable Global Interrupts
	sei();
}
// Initialize SPI Master Device (with SPI interrupt)
void spi_init_master (void)
{
	// Set MOSI, SCK as Output
	DDRB=(1<<5)|(1<<3);
	
	// Enable SPI, Set as Master
	// Prescaler: Fosc/16, Enable Interrupts
	//The MOSI, SCK pins are as per ATMega8
	SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPIE);
	
	// Enable Global Interrupts
	sei();
}
char SPI_Transmit(char cData){

	SPDR = cData;
	while(!(SPSR & (1<<SPIF)))
	;
	return SPDR;
}

//
int main(void)
{
	
    while(1)
    {
		
        //TODO:: Please write your application code 
    }
}