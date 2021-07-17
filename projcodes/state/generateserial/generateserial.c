//
// Created by mahdi on 7/5/2021.
//

#include "../../all.h"


void GenerateSerial_Init()
{
    Lcd_ClearScreen(LCDKEYPAD);
	Lcd_Position(LCDKEYPAD,0,0);
	Lcd_Prints(LCDKEYPAD,"Your Serial: ");
	Store_Update();
	Lcd_Position(LCDKEYPAD,1,0);
	Lcd_Prints(LCDKEYPAD,"N:Confirm P:Back");
}

void GenerateSerial_ProcessKey(int_fast8_t key)
{
	if(key == 31)
	{
		Lcd_ClearScreen(LCDKEYPAD);
		Lcd_Position(LCDKEYPAD,0,3);
		Lcd_Prints(LCDKEYPAD,"Thank You");
		_delay_ms(2000);
		States_GotoState(IDLE);
	}
	else if(key == 30)
	{
		/*States_GotoState(ENTERING_PHONE);	// if re-editing is permitted*/
	}
	else 
	{
		
	}
}