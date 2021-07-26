#include "../../all.h"

void EnteringTemp_Init()
{
	Lcd_PrintLine(LCDKEYPAD, 0, "Temperature:");
    Lm35_Init();
}

void EnteringTemp_Refresh()
{
	float tempF = Lm35_GetTemp();
	char tempF_txt[20];
	dtostrf(tempF, 5, 2, tempF_txt);
	Lcd_PrintLine(LCDKEYPAD, 1, tempF_txt);
	strcpy(keyBuffer, tempF_txt);
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