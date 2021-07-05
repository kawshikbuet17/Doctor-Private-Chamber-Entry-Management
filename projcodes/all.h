#ifndef ALL_H_ADDED
#define ALL_H_ADDED

#include "avr/io.h"
#include "error.h"
#include "states.h"
#include "idle.h"


#define D4 eS_PORTD5
#define D5 eS_PORTD4
#define D6 eS_PORTD3
#define D7 eS_PORTD2
#define RS eS_PORTD7
#define EN eS_PORTD6

#include "lcd_4bit.h"

#include "hc05.h"
#include "keypad8.h"
#include "keyprocessor.h"

#endif