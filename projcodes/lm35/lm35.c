#include "../all.h"

void Lm35_Init()
{
	ADCSRA = 0x81; 		//enable ADC with div factor 2
	ADMUX = 0xC0; 		//internal voltage 2.56V, right-justified, input ADC0
	DDRA &= ~1;
}

void Lm35_PrintTemp()
{
	float tempF = Lm35_GetTemp();
	char tempF_txt[20];
	dtostrf(tempF, 5, 2, tempF_txt);
	Lcd_PrintLine(LCDKEYPAD, 1, tempF_txt);
	strcpy(keyBuffer, tempF_txt);
	_delay_ms(10);
}

float Lm35_GetTemp()
{
	float tempC, tempF, vref = 2.56;

	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC));

	unsigned int i = ADC;
	tempC = (i * vref * 1000.0) / (10.0 * 1024);
	tempF = tempC * (9.0 / 5)  + 32.0;

	return tempF;
}