#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#define D4 eS_PORTC0
#define D5 eS_PORTC1
#define D6 eS_PORTC2
#define D7 eS_PORTC3
#define RS eS_PORTC5
#define EN eS_PORTC4

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include <string.h>
#include <stdlib.h>

int main (void)
{
	DDRC = 0xFF;
	ADCSRA = 0x85; 		//make ADC enable and div factor = 32
	ADMUX = 0xC0; 		//2.56V, right-justified, input ADC0

	unsigned int i;
	float tempC, vref = 2.56;

	char label[50];
	char temp_txt[20];
	strcpy(label, "Temperature: ");
	
	Lcd4_Init();
	Lcd4_Set_Cursor(1,1);
	Lcd4_Write_String(label);
	
	while (1){
		ADCSRA |= (1<<ADSC);	 	//start conversion
		while((ADCSRA & (1<<ADSC))==0); 	//wait for end of conversion
		i = ADC;
		tempC = (i * vref * 1000.0) / (10.0 * 1024);

		Lcd4_Set_Cursor(1, strlen(label)+1);
		dtostrf(tempC, 5, 2, temp_txt);
		Lcd4_Write_String(temp_txt);
		
		_delay_ms(20);
	}
	return 0;
}