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
	
	
	Lcd_Prints(LCDKEYPAD , "starting");
	Lcd_Position(LCDKEYPAD , 0,0);
	
	HC05_Init_ATCommand_Mode();
	//HC05_Init_Data_Mode();
	_delay_ms(500);
	
	Lcd_ClearScreen(LCDKEYPAD);
	
	HC05_SendString("AT+ROLE=1\r\n");
	
	
	Lcd_Prints(LCDKEYPAD , "re:");
	
	while (1)
	{
		const char c = HC05_ReceiveChar();
		Lcd_Printc(LCDKEYPAD , c);
		
	}
}
