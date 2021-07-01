/*
 * GccApplication1.c
 *
 * Created: 7/1/2021 11:43:48 PM
 * Author : mahdi
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRD = 0xFF;
	PORTD = 0xFF;
    while (1) 
    {
		PORTD = ~PORTD;
		_delay_ms(1000);
    }
}

