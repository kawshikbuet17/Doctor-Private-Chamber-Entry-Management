void lm35_init()
{
	DDRC = 0xFF;
	ADCSRA = 0x85; 		//enable ADC with div factor 32
	ADMUX = 0xC0; 		//2.56V, right-justified, input ADC0
}

float lm35_getTemp()
{
	unsigned int i;
	float tempC, tempF, vref = 2.56;

	ADCSRA |= (1<<ADSC);	 	//start conversion
	while((ADCSRA & (1<<ADSC))==0); 	//wait for end of conversion
	i = ADC;
	tempC = (i * vref * 1000.0) / (10.0 * 1024);
	tempF = tempC * (9.0 / 5)  + 32.0;

	return tempF;
}
