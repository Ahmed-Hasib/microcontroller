/*
 * max7219_attiny45.c
 *
 * Created: 8/27/2017 02:29:20 PM
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

 


int main(void)
{
	DDRB |=(1<<PINB0) |(1<<PINB1) |(1<<PINB2);
	int i=0;
	
	
	
    while(1)
    {
		cs_l;
		for(i=0;i<8;i++)
		{
			cl_l;
			d_h;
			cl_h;
			_delay_ms(2);
			
		}
		cs_h;
        //TODO:: Please write your application code 
    }
}