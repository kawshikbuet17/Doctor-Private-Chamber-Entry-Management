//
// Created by mahdi on 7/5/2021.
//

#include "../../all.h"

void UpdateKeyMode()
{
	const char * s = Keypad_GetMode();
	Lcd_Position(LCDKEYPAD,0,16-strlen(s));
	Lcd_Prints(LCDKEYPAD,s);
}
void EnteringName_Init()
{
    Lcd_ClearScreen(LCDKEYPAD);
    Lcd_Position(LCDKEYPAD,0,0);
    Lcd_Prints(LCDKEYPAD,"Enter Name:");
	UpdateKeyMode();
}

void EnteringName_ProcessKey(int_fast8_t key)
{
	if(key == 31)
	{
		// nxt
	}
	else if(key == 30)
	{
		
	}
	else 
	{
		Keypad_AddKey(key);
		Lcd_Position(LCDKEYPAD,1,0);
		int sz = strlen(keyBuffer);
		Lcd_Prints(LCDKEYPAD , keyBuffer);
		sz  = 16-sz;
		while(sz--)
			Lcd_Printc(LCDKEYPAD,' ');
		HC05_SendString(keyBuffer);
		
		UpdateKeyMode();
	}
}