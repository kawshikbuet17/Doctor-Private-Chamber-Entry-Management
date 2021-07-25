
#ifndef STATES_H_ADDED
#define STATES_H_ADDED



#define IDLE 0
#define ENTERING_NAME 1
#define ENTERING_AGE 2
#define ENTERING_PHONE 3
#define GENERATE_SERIAL 4

#include <avr/io.h>
#include "idle/idle.h"
void States_GotoState(int_fast8_t);

#endif