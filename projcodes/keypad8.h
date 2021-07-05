#ifndef KEYPAD8_H_ADDED
#define KEYPAD8_H_ADDED

#include "all.h"

void Keypad_Init();
int_fast8_t Keypad_KeyPressed();
int_fast8_t Keypad_GetRow();
int_fast8_t Keypad_GetCol();
int_fast8_t Keypad_GetKey();

#endif