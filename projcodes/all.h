#ifndef ALL_H_ADDED
#define ALL_H_ADDED

#include "stdbool.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "avr/io.h"
#include "error.h"
#include "state/states.h"
#include "state/idle/idle.h"
#include "state/enteringname/enteringname.h"
#include "state/enteringage/enteringage.h"
#include "state/enteringphone/enteringphone.h"
#include "state/generateserial/generateserial.h"
#include "store/store.h"

#include "lcd/lcdgeneric.h"

#include "hc05/hc05.h"
#include "keypad/keypad8.h"
#include "keyprocessor.h"

#endif