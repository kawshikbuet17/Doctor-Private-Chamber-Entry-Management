//
// Created by mahdi on 7/5/2021.
//

#include "../../all.h"

//extern struct storeRecords records[100];
//extern unsigned int serial;


void EnteringPhone_Init()
{
	
    Lcd_PrintLine(LCDKEYPAD,0,"Phone no:");
	
	Keypad_InitNumpad();
	Keypad_UpdateKeyMode();
	
	//restore old age
	Keypad_WriteToBuffer(currentPatient.phone);
	Lcd_PrintLine(LCDKEYPAD , 1 , keyBuffer);
}

void EnteringPhone_ProcessKey(int_fast8_t key)
{
	if(key == 31)
	{
		// nxt
		
		// save phone patient
		Patient_UpdatePhone(&currentPatient , keyBuffer);
		Keypad_ResetBuffer();
		States_GotoState(ENTERING_TEMP);
		// print serial
	}
	else if(key == 30)
	{
		// prev
		// save phone 
		Patient_UpdatePhone(&currentPatient , keyBuffer);
		
		Keypad_ResetBuffer();
		States_GotoState(ENTERING_AGE);
	}
	else 
	{
		Keypad_AddKey(key);
		
		Lcd_PrintLine(LCDKEYPAD , 1 , keyBuffer);
		
		HC05_SendString(keyBuffer);
		
		Keypad_InitNumpad();
		Keypad_UpdateKeyMode();
	}
}