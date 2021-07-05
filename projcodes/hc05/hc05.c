#include <avr/io.h>
#include "hc05.h"

#ifndef F_CPU
# warning "F_CPU not defined in hc05.h"
#define F_CPU 1000000UL
#endif



void HC05_Init_Data_Mode()
{
	// communication properties = baud rate 9600 , Data bits:8, Stop bit:1,Parity:No parity
	
	
	
	UCSRA = 1<<U2X; // no interrupt ,  double speed 
	
	UCSRB = (1 << RXEN) | (1 << TXEN);				// Enable USART transmitter and receiver 
	
	UCSRC  = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0); // data bit 8 , stop bit 1 
	
	// double speed , UBRR = f_cpu / 8 / 9600 - 1	
	#define UBRR ((F_CPU)/8UL/9600UL - 1)
	
	UBRRL = UBRR;   // set ubrrl
	UBRRH = UBRR>>8; // set ubrrh
	
}
char HC05_ReceiveChar()
{
	while (!(UCSRA & (1 << RXC)));					/* Wait until new data receive */
	return (UDR);
}
void HC05_SendChar(char data)
{
	UDR = data;										/* Write data to be transmitting in UDR */
	while (!(UCSRA & (1<<UDRE)));					/* Wait until data transmit and buffer get empty */
}
void HC05_SendString(char * s)
{
	while(*s)
		HC05_SendChar(*(s++));
}