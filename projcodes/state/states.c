#include "../all.h"

volatile int_fast8_t currentState;

void States_GotoState(int_fast8_t newState)
{
	switch(newState)
	{
		case IDLE:
			Idle_Init();
			break;
		case ENTERING_NAME:
			EnteringName_Init();
			break;
		default:
			Error_Error("GotoState: newState not defined");
	}
	currentState = newState;
}