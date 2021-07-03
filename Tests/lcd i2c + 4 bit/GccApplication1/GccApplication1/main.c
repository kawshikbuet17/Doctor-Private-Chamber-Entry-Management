/*
 * lcd_test_adc.c
 *
 * Created: 19-Feb-19 19:46:12
 *  Author: David Prentice
 */

#define F_CPU 1000000
#include <util/delay.h>
#include <avr/io.h>
#include "lcd.h"
extern void lcd_backlight(char on);   //not in lcd.h

#include <stdlib.h>       //for itoa()

#define D4 eS_PORTD5
#define D5 eS_PORTD4
#define D6 eS_PORTD3
#define D7 eS_PORTD2
#define RS eS_PORTD7
#define EN eS_PORTD6

#include "lcd_4bit.h"

int main(void)
{
	
	DDRD = DDRD | 0b11111100;
	
	
	Lcd4_Init();
	
	Lcd4_Set_Cursor(1,1);
	Lcd4_Write_String("eta ki jinish");
	
	
    lcd_init(LCD_ON_DISPLAY);
    lcd_backlight(0);
    _delay_ms(200);
    lcd_backlight(1);
    _delay_ms(200);
    
    while (1)
    {
        lcd_clrscr();
        lcd_gotoxy(0, 0);
        lcd_puts("Na re vai");
        _delay_ms(250);
    }
}