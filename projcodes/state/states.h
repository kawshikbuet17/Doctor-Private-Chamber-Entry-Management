
#ifndef STATES_H_ADDED
#define STATES_H_ADDED



#define IDLE 0
#define ENTERING_NAME 1
#define ENTERING_AGE 2
#define ENTERING_PHONE 3
#define ENTERING_TEMP 4
#define ENTERING_BP 5
#define GENERATE_SERIAL 6

#include <avr/io.h>
#include "idle/idle.h"
void States_GotoState(int_fast8_t);
void States_Refresh();

#endif