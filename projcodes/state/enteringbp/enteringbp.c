#include "../../all.h"

void EnteringBp_Init()
{
    Lcd_PrintLine(LCDKEYPAD,0,"Enter Bp: ");
	
	Bp_Init();
	EnteringBp_getBp();
}

void EnteringBp_getBp()
{
	int_fast8_t x = 0;
	while(1) {
		Bp_PrintBp();
		if(Keypad_KeyPressed()) {
			x = Keypad_GetKey();
			break;
		}
	}
	_delay_ms(20);
	EnteringBp_ProcessKey(x);
	Keypad_Init();
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