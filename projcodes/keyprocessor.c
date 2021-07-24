#include "all.h"

extern int_fast8_t currentState;
void KeyProcessor_ProcessKey(int_fast8_t key)
{
	switch(currentState)
	{
		case IDLE:
			Idle_ProcessKey(key);
			break;
		case ENTERING_NAME :
			EnteringName_ProcessKey(key);
			break;
		case ENTERING_AGE :
			EnteringAge_ProcessKey(key);
			break;
		case ENTERING_PHONE :
			EnteringPhone_ProcessKey(key);
			break;
		case ENTERING_TEMP :
			EnteringTemp_ProcessKey(key);
			break;
		case ENTERING_BP :
			EnteringBp_ProcessKey(key);
			break;
		case GENERATE_SERIAL :
			GenerateSerial_ProcessKey(key);
			break;
		default:
			Error_Error("ProcessKey: Undefined Current State");
	}
}