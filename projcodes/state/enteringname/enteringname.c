//
// Created by mahdi on 7/5/2021.
//

#include "../../all.h"

//extern struct storeRecords records[100];
//extern unsigned int serial;

void EnteringName_Init()
{
    Lcd_ClearScreen(LCDKEYPAD);
    Lcd_Position(LCDKEYPAD,0,0);
    Lcd_Prints(LCDKEYPAD,"Enter Name:");
	Keypad_UpdateKeyMode();
	
	Keypad_WriteToBuffer(currentPatient.name);
	Lcd_PrintLine(LCDKEYPAD , 1 , keyBuffer);
}

void EnteringName_ProcessKey(int_fast8_t key)
{
	if(key == 31)
	{
		// nxt
		// save name and procced
		Patient_UpdateName(&currentPatient , keyBuffer);
		Keypad_ResetBuffer();
		States_GotoState(ENTERING_AGE);
	}
	else if(key == 30)
	{
		//prev
		// save name and procced
		Patient_UpdateName(&currentPatient , keyBuffer);
		Keypad_ResetBuffer();
		States_GotoState(IDLE);
	}
	else 
	{
		Keypad_AddKey(key);
		// print input in lower line
		Lcd_PrintLine(LCDKEYPAD , 1 , keyBuffer);
		HC05_SendString(keyBuffer);
		
		Keypad_UpdateKeyMode();
	}
}