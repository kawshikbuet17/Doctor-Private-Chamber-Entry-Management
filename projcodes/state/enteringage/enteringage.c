//
// Created by mahdi on 7/5/2021.
//

#include "../../all.h"

//extern struct storeRecords records[100];
//extern unsigned int serial;

void EnteringAge_Init()
{
	// clear screen of keypad display , 
	// since both row is used and printed ' ' 
	// so no clear screen func is required
    Lcd_PrintLine(LCDKEYPAD,0,"Enter Age:");
	Keypad_InitNumpad();
	Keypad_UpdateKeyMode();
	
	// restore old age
	Keypad_WriteToBuffer(currentPatient.age);
	Lcd_PrintLine(LCDKEYPAD , 1 , keyBuffer);
}

void EnteringAge_ProcessKey(int_fast8_t key)
{
	if(key == 31)
	{
		// nxt
		
		// save age
		Patient_UpdateAge(&currentPatient , keyBuffer);
		
		Keypad_ResetBuffer();
		States_GotoState(ENTERING_PHONE);
	}
	else if(key == 30)
	{
		// prev
		
		// save age
		Patient_UpdateAge(&currentPatient , keyBuffer);
		
		Keypad_ResetBuffer();
		States_GotoState(ENTERING_NAME);
	}
	else 
	{
		Keypad_AddKey(key);
		
		Lcd_PrintLine(LCDKEYPAD , 1 , keyBuffer);
		HC05_SendString(keyBuffer);
		
		Keypad_UpdateKeyMode();
	}
}