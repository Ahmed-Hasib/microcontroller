/*
 * attiny45.c
 *
 * Created: 8/6/2017 12:48:16 PM
 *  Author: Hasib
 */ 


#include <avr/io.h>
#include<util/delay.h>



// Initialize SPI Master Device (without interrupt)
void spi_init_master (void)
{
	// Set MOSI, SCK as Output
	DDRB = (1<<5)|(1<<3);
	
	// Enable SPI, Set as Master
	//Prescaler: Fosc/16, Enable Interrupts
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

int main(void)
{
	DDRB |=(1<<PINB0);
    while(1)
    {
		PORTB |=(1<<PINB0);
		
		PORTB &=~(1<<PINB0);
		
        //TODO:: Please write your application code 
    }
}