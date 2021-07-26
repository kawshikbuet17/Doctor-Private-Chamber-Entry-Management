/*
 * GccApplication1.c
 *
 * Created: 7/4/2021 4:14:07 PM
 * Author : mahdi
 */ 

#include "all.h"

int main(void)
{
		
	HC05_Init_Data_Mode();
	//HC05_Init_ATCommand_Mode();
	
	HC05_SendString("hello there");
	
	Lcd_Init(LCDKEYPAD);
	Lcd_Init(LCDNOTICE);
	
	Lcd_Position(LCDNOTICE , 0,0);
	Lcd_Prints(LCDNOTICE , "abcdefghijklmnopqrstuvwxyz");
	Lcd_Position(LCDNOTICE , 0,0);
	Lcd_Prints(LCDNOTICE , "abcdefghijklmnopqrstuvwxyz");
	Lcd_Prints(LCDNOTICE , "abcdefghijklmnopqrstuvwxyz");
	
	States_GotoState(IDLE);
	Keypad_Init();
	
	while (1)
	{
		if(Keypad_KeyPressed())
		{
			_delay_ms(20);
			if(Keypad_KeyPressed())
			{
				int_fast8_t x = Keypad_GetKey();
				_delay_ms(20);
				KeyProcessor_ProcessKey(x);
				Keypad_Init();
			}
		}
		States_Refresh();
	}
}
