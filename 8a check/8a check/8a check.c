/*
 * _8a_check.c
 *
 * Created: 7/29/2017 01:16:29 PM
 *  Author: Hasib
 */ 


#include<avr/io.h>
#include<util/delay.h>
#define db DDRB
#define pb PORTB

#define dc DDRC
#define pc PORTC

#define dd DDRD
#define pd PORTD

#define c1 PINB0 
#define c2 PINB1 
#define c3 PINB2 
#define c4 PINB3 
#define c5 PINB4 
#define c6 PINB5 
#define c7 PINB6
#define c8 PINB7 

#define p1 PIND0
#define p2 PIND1
#define p3 PIND2
#define p4 PIND3
#define p5 PIND4
#define p6 PIND5
#define p7 PIND6
#define p8 PIND7


void print_led(int a[])
{
	int i=0,val=0,tmp=0;
	
 
	for(i=0;i<8;i++)
	{
		
		val=a[i];
		pb=val;
		tmp=i;

		if(tmp==0)
		pd =1;
		else if(tmp==1)
		pd =2;
		else if(tmp==2)
		pd =4;
		else if(tmp==3)
		pd =8;
		else if(tmp==4)
		pd =16;
		else if(tmp==5)
		pd =32;
		else if(tmp==6)
		pd =64;
		else if(tmp==7)
		pd =128;
		
		_delay_ms(.5);
		pb=0;
		pd=0;
		_delay_ms(.5);
	}
 
	
}

int main(void)
{
	
	db |=(1<<c1) |(1<<c2) |(1<<c3) |(1<<c4) |(1<<c5) |(1<<c6) |(1<<c7) |(1<<c8);
	//pb |=(1<<c1) |(1<<c2) |(1<<c3) |(1<<c4) |(1<<c5) |(1<<c6)|(1<<c7) |(1<<c8);
	
	
	DDRD |=(1<<PIND0) |(1<<PIND1)  |(1<<PIND2)  |(1<<PIND3)  |(1<<PIND4)  |(1<<PIND5)  |(1<<PIND6)  |(1<<PIND7) ;
   // PORTD |=(1<<PIND0) |(1<<PIND1)  |(1<<PIND2)  |(1<<PIND3)  |(1<<PIND4)  |(1<<PIND5)  |(1<<PIND6) |(1<<PIND7) ;
   //PORTD |=(1<<PIND1);
    
    while(1)
    {
		   
	   int box[8]={255, 195, 165, 153, 153, 165, 195, 255};
	   int box1[8]={0, 126, 66, 66, 66, 66, 126, 0};
	   print_led(box);
	  
	
	 

	  
	  
		
		
		
	}
}