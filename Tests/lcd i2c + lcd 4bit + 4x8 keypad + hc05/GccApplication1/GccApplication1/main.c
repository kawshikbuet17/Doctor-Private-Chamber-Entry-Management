/*
 * GccApplication1.c
 *
 * Created: 7/4/2021 4:14:07 PM
 * Author : mahdi
 */ 

#define F_CPU 1000000
#include <util/delay.h>
#include <avr/io.h>
#include "lcd.h"
extern void lcd_backlight(char on);   //not in lcd.h

#include <stdlib.h>       //for itoa()
#include <stdio.h> // sprintf

#define D4 eS_PORTD5
#define D5 eS_PORTD4
#define D6 eS_PORTD3
#define D7 eS_PORTD2
#define RS eS_PORTD7
#define EN eS_PORTD6

#include "lcd_4bit.h"

#include "hc05.h"
#include "keypad8.h"
int main(void)
{
	
	
	
	HC05_Init_Data_Mode();
	
	//////////////////////////////////////////////////////////////////////////
	//LCD 4 bit
	DDRD = DDRD | 0b11111100;
	Lcd4_Init();
	Lcd4_Set_Cursor(0,0);
	Lcd4_Write_String("etai jinish");
	//////////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////////////////
	//lcd with i2c
	lcd_init(LCD_ON_DISPLAY);
	lcd_backlight(0);
	_delay_ms(500);
	lcd_backlight(1);
	_delay_ms(500);
	
	lcd_clrscr();
	lcd_gotoxy(0, 0);
	lcd_puts("ho re vai");
	//////////////////////////////////////////////////////////////////////////

	Keypad_Init();
	
	while (1)
	{
		if(Keypad_KeyPressed())
		{
			int_fast8_t x = Keypad_GetKey();
			char temp[10];
			sprintf(temp , "key: %d ",x);
			lcd_gotoxy(0,1);
			lcd_puts(temp);
			Keypad_Init();
		}
	}
}
