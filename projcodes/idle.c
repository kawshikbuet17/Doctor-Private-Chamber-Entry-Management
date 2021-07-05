#include "all.h"

void Idle_ProcessKey(int_fast8_t key)
{
	States_GotoState(ENTERING_NAME);
}
void Idle_Init()
{
	Lcd4_Clear();
	Lcd4_Set_Cursor(0,1);
	Lcd4_Write_String("Welcome to xyz");
	Lcd4_Set_Cursor(0,0);
	Lcd4_Write_String("Press any key");
}