#include "all.h"

extern int_fast8_t currentState;
void KeyProcessor_ProcessKey(int_fast8_t key)
{
	switch(currentState)
	{
		case IDLE:
			Idle_ProcessKey(key);
			break;
		default:
			Error_Error("ProcessKey: Undefined Current State");
	}
}