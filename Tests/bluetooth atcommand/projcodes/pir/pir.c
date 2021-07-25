#include "../all.h"

int entryCount = 0;

void Pir_Init()
{
	DDRA &= ~(1 << 2);	// to take PIR input from PA2
	Pir_PrintCount();
}

void Pir_PrintCount()
{
	if(PINA & (1 << 2)) {
		entryCount++;
	}
	char displayStr[20];
	char countStr[10];
	strcpy(displayStr, "EntryCount: ");

	Lcd_ClearScreen(LCDNOTICE);
	Lcd_Position(LCDNOTICE, 0, 0);
	Lcd_Prints(LCDNOTICE, displayStr);

	Lcd_Position(LCDNOTICE, 0, strlen(displayStr) + 1);
	dtostrf((float) entryCount, 5, 0, countStr);
	Lcd_Prints(LCDNOTICE, countStr);
}