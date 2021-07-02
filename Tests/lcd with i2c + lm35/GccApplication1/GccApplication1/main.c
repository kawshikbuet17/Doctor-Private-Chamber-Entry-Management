/*
 * lcd_test_adc.c
 *
 * Created: 19-Feb-19 19:46:12
 *  Author: David Prentice
 */

#define F_CPU 1000000
#include <util/delay.h>
#include "lcd.h"
#include <avr/io.h>
extern void lcd_backlight(char on);   //not in lcd.h

#include <stdlib.h>       //for itoa()
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/// lm35 connected to adc0
	DDRC = 0xFF;
	ADCSRA = 0x85; 		//make ADC enable and div factor = 32
	ADMUX = 0xC0; 		//2.56V, right-justified, input ADC0
	
	unsigned int i;
	float tempC, vref = 2.56;

	char label[50];
	char temp_txt[20];
	strcpy(label, "Temperature: ");
	
    lcd_init(LCD_ON_DISPLAY);
    lcd_backlight(0);
    _delay_ms(200);
    lcd_backlight(1);
    _delay_ms(200);
    lcd_gotoxy(0, 0);
	lcd_puts(label);
	
    while (1)
    {
		
		ADCSRA |= (1<<ADSC);	 	//start conversion
		while((ADCSRA & (1<<ADSC))==0); 	//wait for end of conversion
		i = ADC;
		tempC = (i * vref * 1000.0) / (10.0 * 1024);
		
		lcd_gotoxy(0,1);
		dtostrf(tempC, 5, 2, temp_txt);
		lcd_puts(temp_txt);
		
        _delay_ms(5000);
    }
}