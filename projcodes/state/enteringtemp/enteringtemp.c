#include "../../all.h"

void EnteringTemp_Init()
{
	Lcd_PrintLine(LCDKEYPAD, 0, "Temperature:");
    Lm35_Init();
	EnteringTemp_getTemp();
}

void EnteringTemp_getTemp()
{
	int_fast8_t x = 0;
	while(1) {
		Lm35_PrintTemp();
		if(Keypad_KeyPressed()) {
			x = Keypad_GetKey();
			break;
		}
	}
	_delay_ms(20);
	EnteringTemp_ProcessKey(x);
	Keypad_Init();
}

void EnteringTemp_ProcessKey(int_fast8_t key)
{
	if(key == 31)
	{
		Patient_UpdateTemperature(&currentPatient , keyBuffer);
		Keypad_ResetBuffer();
		States_GotoState(ENTERING_BP);
	}
	else if(key == 30)
	{
		Patient_UpdateTemperature(&currentPatient , keyBuffer);
		Keypad_ResetBuffer();
		States_GotoState(ENTERING_PHONE);
	}
}