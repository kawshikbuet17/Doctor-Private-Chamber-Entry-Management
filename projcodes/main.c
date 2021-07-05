/*
 * GccApplication1.c
 *
 * Created: 7/4/2021 4:14:07 PM
 * Author : mahdi
 */ 

#define F_CPU 1000000
#include <util/delay.h>
#include <avr/io.h>

#include <stdlib.h>       //for itoa()
#include <stdio.h> // sprintf

#include "all.h"

int main(void)
{
		
	HC05_Init_Data_Mode();
	Lcd_Init(LCDKEYPAD);
	Lcd_Init(LCDNOTICE);
	
	States_GotoState(IDLE);
	Keypad_Init();
	
	for(int i=0;i<26;i++)
	{
		Lcd_Position(LCDNOTICE , i/16, i%16);
		Lcd_Printc(LCDNOTICE , 'a' + i);
		
		Lcd_Position(LCDKEYPAD , i/16, i%16);
		Lcd_Printc(LCDKEYPAD , 'a' + i);
	}
	
	
	
	while (1)
	{
		if(Keypad_KeyPressed())
		{
			int_fast8_t x = Keypad_GetKey();
			KeyProcessor_ProcessKey(x);
			Keypad_Init();
		}
	}
}
