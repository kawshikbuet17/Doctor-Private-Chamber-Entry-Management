//
// Created by mahdi on 7/5/2021.
//

#include "../../all.h"

//extern struct storeRecords records[100];
//extern unsigned int serial;


void EnteringPhone_Init()
{
    Lcd_ClearScreen(LCDKEYPAD);
    Lcd_Position(LCDKEYPAD,0,0);
    Lcd_Prints(LCDKEYPAD,"Phone no:");
	Keypad_InitNumpad();
	Keypad_UpdateKeyMode();
}

void EnteringPhone_ProcessKey(int_fast8_t key)
{
	if(key == 31)
	{
		// nxt
		//records[serial].phone = keyBuffer;
		// save phone information
		// print serial
	}
	else if(key == 30)
	{
		// prev
		Keypad_ResetBuffer();
		States_GotoState(ENTERING_AGE);
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
		
		Keypad_InitNumpad();
		Keypad_UpdateKeyMode();
	}
}