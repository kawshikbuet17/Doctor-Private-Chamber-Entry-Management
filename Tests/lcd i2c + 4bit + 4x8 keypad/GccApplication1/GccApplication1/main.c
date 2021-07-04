

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

#include "USART_RS232_H_file.h"		/* include USART library */


int main(void)
{
	
	
	
	USART_Init(9600);						/* initialize USART with 9600 baud rate */
	
	//////////////////////////////////////////////////////////////////////////
	//LCD 4 bit
	DDRD = DDRD | 0b11111100; 
	Lcd4_Init();
	Lcd4_Set_Cursor(1,1);
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
	
	USART_SendString("hello there");
	
	lcd_puts("sent");
	int count  = 0;
	
    while (1)
    {
		char Data_in;
		Data_in = USART_RxChar();						/* receive data from Bluetooth device*/
		char temp[100];
		sprintf(temp , "count = %d",count);
		if(Data_in =='1')
		{
			Lcd4_Init();
			Lcd4_Write_String(temp);
		}
		else if(Data_in =='2')
		{
			lcd_clrscr();
			lcd_puts(temp);
		}
		else
			USART_SendString("Select proper option");	/* send message for selecting proper option */
		lcd_puts("hehe");
    }
}