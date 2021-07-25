//
// Created by mahdi on 7/5/2021.
//

#include "../all.h"

void Store_Update()
{
	const char * s;
	dtostrf((float)(++patientsCount), 3, 0, s);
	Lcd_Position(LCDKEYPAD,0,13);
	Lcd_Prints(LCDKEYPAD,s);
}