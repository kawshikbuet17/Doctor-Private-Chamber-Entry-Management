#ifndef KEYPAD8_H_ADDED
#define KEYPAD8_H_ADDED

#include "../all.h"
extern char keyBuffer[17];

void Keypad_Init();
int_fast8_t Keypad_KeyPressed();
int_fast8_t Keypad_GetRow();
int_fast8_t Keypad_GetCol();
int_fast8_t Keypad_GetKey();
const char * Keypad_GetMode();
void Keypad_AddKey(int_fast8_t key);
void Keypad_UpdateKeyMode();
void Keypad_ResetBuffer();
void Keypad_InitNumpad();
void Keypad_WriteToBuffer(char * newData);

#endif