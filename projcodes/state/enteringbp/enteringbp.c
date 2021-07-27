#include "../../all.h"

bool scanning = 0;
void EnteringBp_Init()
{
    Lcd_PrintLine(LCDKEYPAD,0,"Finger on green-");
	Lcd_PrintLine(LCDKEYPAD , 1, "Light, press next");
	Bp_Init();
	scanning = 0;
}

void EntetingBp_Refresh()
{
	
}

void EnteringBp_ProcessKey(int_fast8_t key)
{
	if(key == 31)
	{
		if(scanning == 0)
		{
			scanning = 1;
			Lcd_PrintLine(LCDKEYPAD , 1, "Light");
			Bp_PrintBp();
		}
		else 
		{
			scanning = 0;
			Patient_UpdateBp(&currentPatient , keyBuffer);
			Keypad_ResetBuffer();
			States_GotoState(GENERATE_SERIAL);
		}
		// print serial
	}
	else if(key == 30)
	{
		Patient_UpdateBp(&currentPatient , keyBuffer);
		Keypad_ResetBuffer();
		States_GotoState(ENTERING_TEMP);
	}
}