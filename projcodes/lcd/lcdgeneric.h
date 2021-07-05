#ifndef LCDGENERIC_H_ADDED
#define LCDGENERIC_H_ADDED

#include "../all.h"

#define LCDKEYPAD 0 // LcdType
#define LCDNOTICE 1 // LcdType


#define D4 eS_PORTD5
#define D5 eS_PORTD4
#define D6 eS_PORTD3
#define D7 eS_PORTD2
#define RS eS_PORTD7
#define EN eS_PORTD6
#include "lcd_4bit.h"

#include "lcd.h"
extern void lcd_backlight(char on);   //not in lcd.h

void Lcd_Init(int_fast8_t lcdType);
void Lcd_ClearScreen(int_fast8_t lcdType);
void Lcd_Prints(int_fast8_t lcdType ,const char * s);
void Lcd_Position(int_fast8_t lcdType,int x,int y);
void Lcd_Printc(int_fast8_t lcdType ,const char c);

#endif