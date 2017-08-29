/*
 * first.c
 *
 * Created: 6/17/2017 01:51:10 PM
 *  Author: Hasib
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{ 
	DDRB |=(1<<PINB0);
	PORTB &= ~(1<<PINB0);
	DDRB &= ~(1<<PINB1);
	PORTB |=(1<<PINB1);
    while(1)
    {
		if(bit_is_clear(PINB,1))
		{
			PORTB |=(1<<PINB0);
			
		}
		else
		{
			//PORTB |=(1<<PINB0);
			//_delay_ms(500);
			PORTB &= ~(1<<PINB0);
			//_delay_ms(500);
		}
		
		
    }
}