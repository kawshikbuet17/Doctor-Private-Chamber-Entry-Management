//
// Created by mahdi on 7/5/2021.
//

#include "../all.h"

struct storeRecords records[100];
unsigned int serial = 0;

void Store_Update()
{
	const char * s;
	dtostrf((float)(serial+1), 3, 0, s);
	Lcd_Position(LCDKEYPAD,0,13);
	Lcd_Prints(LCDKEYPAD,s);
	serial++;
}