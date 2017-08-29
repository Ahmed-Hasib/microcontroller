/*
 * attiny45.c
 *
 * Created: 8/6/2017 12:48:16 PM
 *  Author: Hasib
 */ 


#include <avr/io.h>
#include<util/delay.h>





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