/*
 * GccApplication1.c
 *
 * Created: 7/4/2021 4:14:07 PM
 * Author : mahdi
 */ 

#include "all.h"

int main(void)
{
	
	Lcd_Init(LCDKEYPAD);
	Lcd_Init(LCDNOTICE);	
	Keypad_Init();
	
	Lcd_Prints(LCDKEYPAD , "starting");
	Lcd_Position(LCDKEYPAD , 0,0);
	
	HC05_Init_ATCommand_Mode();
	//HC05_Init_Data_Mode();
	_delay_ms(500);
	
	Lcd_ClearScreen(LCDKEYPAD);
	
	Lcd_Prints(LCDKEYPAD , "re:");
	
	while (1)
	{
		if(HC05_ReceiveAvailable())
		{
			const char c = HC05_ReceiveChar();
			Lcd_Printc(LCDKEYPAD , c);
		}
		
		if(Keypad_KeyPressed())
		{
			_delay_ms(20);
			if(Keypad_KeyPressed())
			{
				int_fast8_t x = Keypad_GetKey();
				if(x == 0)
				{
					// 1 , send at
					HC05_SendString("AT\r\n");
					Lcd_ClearScreen(LCDKEYPAD);
					Lcd_Prints(LCDKEYPAD , "at:");
				}
				else if(x == 1)
				{
					// 2 , send at+reset
					HC05_SendString("AT+RESET\r\n");
					Lcd_ClearScreen(LCDKEYPAD);
					Lcd_Prints(LCDKEYPAD , "at+reset:");
				}
				else if(x == 2)
				{
					// 3 , send at+role=0
					HC05_SendString("AT+ROLE=0\r\n");
					Lcd_ClearScreen(LCDKEYPAD);
					Lcd_Prints(LCDKEYPAD , "AT+ROLE=0:");
				}
				else if(x==3)
				{
					// d , send at+role=1
					HC05_SendString("AT+ROLE=1\r\n");
					Lcd_ClearScreen(LCDKEYPAD);
					Lcd_Prints(LCDKEYPAD , "AT+ROLE=1:");
				}
				else 
				{
					Lcd_ClearScreen(LCDKEYPAD);
					Lcd_Prints(LCDKEYPAD , "no:");
				}
				_delay_ms(500);
			}
			Keypad_Init();
		}
	}
}
