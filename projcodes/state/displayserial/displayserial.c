#include "../../all.h"

char curr[5];
void DisplaySerial()
{
	Lcd_Position(LCDNOTICE,0,0);
	Lcd_Prints(LCDNOTICE,"Current: ");
	Current_Serial();
	Lcd_Position(LCDNOTICE,1,0);
	Lcd_Prints(LCDNOTICE,"Next: ");
	Next_Serial();
}

void Current_Serial()
{
	dtostrf((float) currentPatientSerial(), 4, 0, curr);
	Lcd_Position(LCDNOTICE, 0, 9);
	Lcd_Prints(LCDNOTICE, curr);
}

void Next_Serial()
{
	dtostrf((float) nextPatientSerial(), 4, 0, curr);
	Lcd_Position(LCDNOTICE, 1, 6);
	Lcd_Prints(LCDNOTICE, curr);
}