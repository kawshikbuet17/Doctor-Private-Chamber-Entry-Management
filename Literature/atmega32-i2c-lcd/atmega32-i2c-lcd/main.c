/*
 * lcd_test_adc.c
 *
 * Created: 19-Feb-19 19:46:12
 *  Author: David Prentice
 */

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
extern void lcd_backlight(char on);   //not in lcd.h

#include <stdlib.h>       //for itoa()

int main(void)
{
    lcd_init(LCD_ON_DISPLAY);
    lcd_backlight(0);
    _delay_ms(200);
    lcd_backlight(1);
    _delay_ms(200);
    
    while (1)
    {
        lcd_clrscr();
        lcd_gotoxy(0, 0);
        lcd_puts("Value: ");
        _delay_ms(250);
    }
}