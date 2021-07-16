#include "../../all.h"

void Idle_ProcessKey(int_fast8_t key)
{
	States_GotoState(ENTERING_NAME);
}
void Idle_Init()
{
	Lcd_ClearScreen(LCDKEYPAD);
	Lcd_Position(LCDKEYPAD , 0,0);
	Lcd_Prints(LCDKEYPAD , "Welcome!");
	Lcd_Position(LCDKEYPAD , 1,0);
	Lcd_Prints(LCDKEYPAD , "1. New Entry");
}