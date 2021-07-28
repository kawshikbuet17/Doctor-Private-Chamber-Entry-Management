#include "../all.h"

void Lm35_Init()
{
	ADMUX = 0b11000000; 		//internal voltage 2.56V, right-justified, input ADC0
	ADCSRA =0b10000000; 		//enable = true ,start conversion = false , auto trigger = false , 
							//interrupt flag = false  ,interrupt enable = false ,  prescaler factor 2
	DDRA &= ~1;
}


float Lm35_GetTemp()
{
	float tempC, tempF, vref = 2.56;

	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC));

	unsigned int i = ADC;
	//tempC = i/4;  
	tempF = i * 9.0 / 20  + 32.0;

	return tempF;
}