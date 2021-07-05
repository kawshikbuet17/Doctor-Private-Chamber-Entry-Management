#include "all.h"

void pinChange(int a, int b)
{
	if(b == 0)
	{
		if(a == eS_PORTA0)
		PORTA &= ~(1<<PA0);
		else if(a == eS_PORTA1)
		PORTA &= ~(1<<PA1);
		else if(a == eS_PORTA2)
		PORTA &= ~(1<<PA2);
		else if(a == eS_PORTA3)
		PORTA &= ~(1<<PA3);
		else if(a == eS_PORTA4)
		PORTA &= ~(1<<PA4);
		else if(a == eS_PORTA5)
		PORTA &= ~(1<<PA5);
		else if(a == eS_PORTA6)
		PORTA &= ~(1<<PA6);
		else if(a == eS_PORTA7)
		PORTA &= ~(1<<PA7);
		else if(a == eS_PORTB0)
		PORTB &= ~(1<<PB0);
		else if(a == eS_PORTB1)
		PORTB &= ~(1<<PB1);
		else if(a == eS_PORTB2)
		PORTB &= ~(1<<PB2);
		else if(a == eS_PORTB3)
		PORTB &= ~(1<<PB3);
		else if(a == eS_PORTB4)
		PORTB &= ~(1<<PB4);
		else if(a == eS_PORTB5)
		PORTB &= ~(1<<PB5);
		else if(a == eS_PORTB6)
		PORTB &= ~(1<<PB6);
		else if(a == eS_PORTB7)
		PORTB &= ~(1<<PB7);
		else if(a == eS_PORTC0)
		PORTC &= ~(1<<PC0);
		else if(a == eS_PORTC1)
		PORTC &= ~(1<<PC1);
		else if(a == eS_PORTC2)
		PORTC &= ~(1<<PC2);
		else if(a == eS_PORTC3)
		PORTC &= ~(1<<PC3);
		else if(a == eS_PORTC4)
		PORTC &= ~(1<<PC4);
		else if(a == eS_PORTC5)
		PORTC &= ~(1<<PC5);
		else if(a == eS_PORTC6)
		PORTC &= ~(1<<PC6);
		else if(a == eS_PORTC7)
		PORTC &= ~(1<<PC7);
		else if(a == eS_PORTD0)
		PORTD &= ~(1<<PD0);
		else if(a == eS_PORTD1)
		PORTD &= ~(1<<PD1);
		else if(a == eS_PORTD2)
		PORTD &= ~(1<<PD2);
		else if(a == eS_PORTD3)
		PORTD &= ~(1<<PD3);
		else if(a == eS_PORTD4)
		PORTD &= ~(1<<PD4);
		else if(a == eS_PORTD5)
		PORTD &= ~(1<<PD5);
		else if(a == eS_PORTD6)
		PORTD &= ~(1<<PD6);
		else if(a == eS_PORTD7)
		PORTD &= ~(1<<PD7);
	}
	else
	{
		if(a == eS_PORTA0)
		PORTA |= (1<<PA0);
		else if(a == eS_PORTA1)
		PORTA |= (1<<PA1);
		else if(a == eS_PORTA2)
		PORTA |= (1<<PA2);
		else if(a == eS_PORTA3)
		PORTA |= (1<<PA3);
		else if(a == eS_PORTA4)
		PORTA |= (1<<PA4);
		else if(a == eS_PORTA5)
		PORTA |= (1<<PA5);
		else if(a == eS_PORTA6)
		PORTA |= (1<<PA6);
		else if(a == eS_PORTA7)
		PORTA |= (1<<PA7);
		else if(a == eS_PORTB0)
		PORTB |= (1<<PB0);
		else if(a == eS_PORTB1)
		PORTB |= (1<<PB1);
		else if(a == eS_PORTB2)
		PORTB |= (1<<PB2);
		else if(a == eS_PORTB3)
		PORTB |= (1<<PB3);
		else if(a == eS_PORTB4)
		PORTB |= (1<<PB4);
		else if(a == eS_PORTB5)
		PORTB |= (1<<PB5);
		else if(a == eS_PORTB6)
		PORTB |= (1<<PB6);
		else if(a == eS_PORTB7)
		PORTB |= (1<<PB7);
		else if(a == eS_PORTC0)
		PORTC |= (1<<PC0);
		else if(a == eS_PORTC1)
		PORTC |= (1<<PC1);
		else if(a == eS_PORTC2)
		PORTC |= (1<<PC2);
		else if(a == eS_PORTC3)
		PORTC |= (1<<PC3);
		else if(a == eS_PORTC4)
		PORTC |= (1<<PC4);
		else if(a == eS_PORTC5)
		PORTC |= (1<<PC5);
		else if(a == eS_PORTC6)
		PORTC |= (1<<PC6);
		else if(a == eS_PORTC7)
		PORTC |= (1<<PC7);
		else if(a == eS_PORTD0)
		PORTD |= (1<<PD0);
		else if(a == eS_PORTD1)
		PORTD |= (1<<PD1);
		else if(a == eS_PORTD2)
		PORTD |= (1<<PD2);
		else if(a == eS_PORTD3)
		PORTD |= (1<<PD3);
		else if(a == eS_PORTD4)
		PORTD |= (1<<PD4);
		else if(a == eS_PORTD5)
		PORTD |= (1<<PD5);
		else if(a == eS_PORTD6)
		PORTD |= (1<<PD6);
		else if(a == eS_PORTD7)
		PORTD |= (1<<PD7);
	}
}

void Lcd4_Port(char a)
{
	if(a & 1)
	pinChange(D4,1);
	else
	pinChange(D4,0);
	
	if(a & 2)
	pinChange(D5,1);
	else
	pinChange(D5,0);
	
	if(a & 4)
	pinChange(D6,1);
	else
	pinChange(D6,0);
	
	if(a & 8)
	pinChange(D7,1);
	else
	pinChange(D7,0);
}
void Lcd4_Cmd(char a)
{
	pinChange(RS,0);             // => RS = 0
	Lcd4_Port(a);
	pinChange(EN,1);            // => E = 1
	_delay_ms(1);
	pinChange(EN,0);             // => E = 0
	_delay_ms(1);
}

void Lcd4_Clear()
{
	Lcd4_Cmd(0);
	Lcd4_Cmd(1);
}

void Lcd4_Set_Cursor(char a, char b)
{
	char temp,z,y;
	if(a == 1)
	{
		temp = 0x80 + b;
		z = temp>>4;
		y = (0x80+b) & 0x0F;
		Lcd4_Cmd(z);
		Lcd4_Cmd(y);
	}
	else if(a == 2)
	{
		temp = 0xC0 + b;
		z = temp>>4;
		y = (0xC0+b) & 0x0F;
		Lcd4_Cmd(z);
		Lcd4_Cmd(y);
	}
}

void Lcd4_Init()
{
	Lcd4_Port(0x00);
	_delay_ms(20);
	///////////// Reset process from datasheet /////////
	Lcd4_Cmd(0x03);
	_delay_ms(5);
	Lcd4_Cmd(0x03);
	_delay_ms(11);
	Lcd4_Cmd(0x03);
	/////////////////////////////////////////////////////
	Lcd4_Cmd(0x02);
	Lcd4_Cmd(0x02);
	Lcd4_Cmd(0x08);
	Lcd4_Cmd(0x00);
	Lcd4_Cmd(0x0C);
	Lcd4_Cmd(0x00);
	Lcd4_Cmd(0x06);
	Lcd4_Clear();
}


void Lcd4_Write_Char(char a)
{
	char temp,y;
	temp = a&0x0F;
	y = a&0xF0;
	pinChange(RS,1);             // => RS = 1
	Lcd4_Port(y>>4);             //Data transfer
	pinChange(EN,1);
	_delay_ms(1);
	pinChange(EN,0);
	_delay_ms(1);
	Lcd4_Port(temp);
	pinChange(EN,1);
	_delay_ms(1);
	pinChange(EN,0);
	_delay_ms(1);
}

void Lcd4_Write_String(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	Lcd4_Write_Char(a[i]);
}

void Lcd4_Shift_Right()
{
	Lcd4_Cmd(0x01);
	Lcd4_Cmd(0x0C);
}

void Lcd4_Shift_Left()
{
	Lcd4_Cmd(0x01);
	Lcd4_Cmd(0x08);
}
//End LCD 4 Bit Interfacing Functions
