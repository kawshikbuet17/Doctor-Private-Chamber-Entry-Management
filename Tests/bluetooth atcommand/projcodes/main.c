/*
 * GccApplication1.c
 *
 * Created: 7/4/2021 4:14:07 PM
 * Author : mahdi
 */ 

#include "all.h"

int main(void)
{
		
	HC05_Init_ATCommand_Mode();
	//HC05_Init_Data_Mode();
	_delay_ms(500);
		
	HC05_SendString("AT\r\n");
	
	
	
	
	Lcd_Init(LCDKEYPAD);
	Lcd_Init(LCDNOTICE);
	
	while (1)
	{
		const char c = HC05_ReceiveChar();
		Lcd_Printc(LCDKEYPAD , c);
	}
}
