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
		case ENTERING_AGE:
			EnteringAge_Init();
			break;
		case ENTERING_PHONE:
			EnteringPhone_Init();
			break;
		case ENTERING_TEMP:
			EnteringTemp_Init();
			break;
		case ENTERING_BP:
			EnteringBp_Init();
			break;
		case GENERATE_SERIAL:
			GenerateSerial_Init();
			break;
		default:
			Error_Error("GotoState: newState not defined");
	}
	currentState = newState;
}
void States_Refresh()
{
	switch(currentState)
	{
		case IDLE:
				
		case ENTERING_NAME:
		
		case ENTERING_AGE:
		
		case ENTERING_PHONE:
		
			break;
		case ENTERING_TEMP:
			EnteringTemp_Refresh();
			break;
		case ENTERING_BP:
			EntetingBp_Refresh();
			break;
		default:
		;
		//Error_Error("States_Refresh: currentstate not defined");
	}
}