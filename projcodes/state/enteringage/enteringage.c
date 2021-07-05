//
// Created by mahdi on 7/5/2021.
//

#include "../../all.h"

extern struct storeRecords records[100];
extern unsigned int serial;

void UpdateKeyMode()
{
	const char * s = Keypad_GetMode();
	Lcd_Position(LCDKEYPAD,0,16-strlen(s));
	Lcd_Prints(LCDKEYPAD,s);
}
void EnteringAge_Init()
{
    Lcd_ClearScreen(LCDKEYPAD);
    Lcd_Position(LCDKEYPAD,0,0);
    Lcd_Prints(LCDKEYPAD,"Enter Age:");
	UpdateKeyMode();
}

void EnteringAge_ProcessKey(int_fast8_t key)
{
	if(key == 31)
	{
		records[serial].age = atoi(keyBuffer);
		States_GotoState(ENTERING_PHONE);
	}
	else if(key == 30)
	{
		States_GotoState(ENTERING_NAME);
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