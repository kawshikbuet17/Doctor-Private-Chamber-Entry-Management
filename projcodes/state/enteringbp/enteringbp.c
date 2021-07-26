#include "../../all.h"

void EnteringBp_Init()
{
	
    Lcd_PrintLine(LCDKEYPAD,0,"Finger on green-");
	Lcd_PrintLine(LCDKEYPAD , 1, "Light ");
	Bp_Init();
}

void EntetingBp_Refresh()
{
	
	Bp_PrintBp();
}

void EnteringBp_ProcessKey(int_fast8_t key)
{
	if(key == 31)
	{
		Patient_UpdateBp(&currentPatient , keyBuffer);
		Keypad_ResetBuffer();
		States_GotoState(GENERATE_SERIAL);
		// print serial
	}
	else if(key == 30)
	{
		Patient_UpdateBp(&currentPatient , keyBuffer);
		Keypad_ResetBuffer();
		States_GotoState(ENTERING_TEMP);
	}
}