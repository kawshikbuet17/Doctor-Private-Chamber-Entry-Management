#include "../all.h"

void Lm35_Init()
{
	ADCSRA = 0x85; 		//enable ADC with div factor 32
	ADMUX = 0xC0; 		//internal voltage 2.56V, right-justified, input ADC0
}

void Lm35_PrintTemp()
{
	float tempF = Lm35_GetTemp();
	char label[50];
	char tempF_txt[20];
	strcpy(label, "Temperature: ");	
	Lcd_ClearScreen(LCDKEYPAD);
	Lcd_Position(LCDKEYPAD, 0, 0);
	Lcd_Prints(LCDKEYPAD, label);
	
	Lcd_Position(LCDKEYPAD, 0, strlen(label)+1);
	dtostrf(tempF, 5, 2, tempF_txt);
	Lcd_Prints(LCDKEYPAD, tempF_txt);
	_delay_ms(10);
}

float Lm35_GetTemp()
{
	float tempC, tempF, vref = 2.56;

	ADCSRA |= (1<<ADSC);
	while((ADCSRA & (1<<ADSC))==0);

	unsigned int i = ADC;
	tempC = (i * vref * 1000.0) / (10.0 * 1024);
	tempF = tempC * (9.0 / 5)  + 32.0;

	return tempF;
}