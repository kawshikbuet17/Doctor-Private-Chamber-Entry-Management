#include "../all.h"

void Idle_ProcessKey(int_fast8_t key)
{
	States_GotoState(ENTERING_NAME);
}
void Idle_Init()
{
	Lcd_ClearScreen(LCDKEYPAD);
	Lcd_Prints(LCDKEYPAD , "Welcome to xyz");
}