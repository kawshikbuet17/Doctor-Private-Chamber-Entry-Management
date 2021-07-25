#ifndef KEY_PROCESSOR_H_ADDED
#define KEY_PROCESSOR_H_ADDED
#include "all.h"
/*
key-> [0,32)  0 1 .. 7
		      8 9 .. 15
			  ...

*/
void KeyProcessor_ProcessKey(int_fast8_t key);

#endif