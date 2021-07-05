#ifndef LCD_4BIT_H_ADDED
#define LCD_4BIT_H_ADDED

#include "../all.h"

//LCD Functions Developed by electroSome
#define eS_PORTA0 0
#define eS_PORTA1 1
#define eS_PORTA2 2
#define eS_PORTA3 3
#define eS_PORTA4 4
#define eS_PORTA5 5
#define eS_PORTA6 6
#define eS_PORTA7 7
#define eS_PORTB0 10
#define eS_PORTB1 11
#define eS_PORTB2 12
#define eS_PORTB3 13
#define eS_PORTB4 14
#define eS_PORTB5 15
#define eS_PORTB6 16
#define eS_PORTB7 17
#define eS_PORTC0 20
#define eS_PORTC1 21
#define eS_PORTC2 22
#define eS_PORTC3 23
#define eS_PORTC4 24
#define eS_PORTC5 25
#define eS_PORTC6 26
#define eS_PORTC7 27
#define eS_PORTD0 30
#define eS_PORTD1 31
#define eS_PORTD2 32
#define eS_PORTD3 33
#define eS_PORTD4 34
#define eS_PORTD5 35
#define eS_PORTD6 36
#define eS_PORTD7 37

#ifndef D4
# warning "D4 not defined"
#endif

#ifndef D5
# warning "D5 not defined"
#endif

#include<util/delay.h>
#include <avr/io.h>

void pinChange(int a, int b);

//LCD 4 Bit Interfacing Functions

void Lcd4_Port(char a);
void Lcd4_Cmd(char a);

void Lcd4_Clear();

void Lcd4_Set_Cursor(char a, char b);
void Lcd4_Init();
void Lcd4_Write_Char(char a);
void Lcd4_Write_String(const char *a);
void Lcd4_Shift_Right();
void Lcd4_Shift_Left();
//End LCD 4 Bit Interfacing Functions

#endif