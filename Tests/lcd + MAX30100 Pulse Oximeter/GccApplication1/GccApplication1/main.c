/*
 * GccApplication1.c
 *
 * Created: 7/27/2021 6:23:02 PM
 * Author : ASUS
 */ 

#include <avr/io.h>
#include "MAX30100_PulseOximeter.h"

#define D4 eS_PORTD5
#define D5 eS_PORTD4
#define D6 eS_PORTD3
#define D7 eS_PORTD2
#define RS eS_PORTD7
#define EN eS_PORTD6
#include "lcd_4bit.h"

#define REPORTING_PERIOD_MS     1000
 
PulseOximeter pox;
uint32_t tsLastReport = 0;
 
void onBeatDetected()
{
    Lcd_Init(0);
    Lcd_Position(0, 0, 0);
    Lcd_Prints(0, "Beat");
}
 
void setup()
{
	Lcd_Init(0);
	Lcd_Position(0, 0, 0);
	Lcd_Prints(0, "Initalizing");
	
	if(!pox.begin()){
		Lcd_Init(0);
		Lcd_Position(0, 0, 0);
		Lcd_Prints(0, "Failed");
	}
	else{
		Lcd_Init(0);
		Lcd_Position(0, 0, 0);
		Lcd_Prints(0, "Failed");
	}
	pox.getRedLedCurrentBias(MAX30100_LED_CURR_7_6MA);
	pox.setOnBeatDetectedCallback(onBeatDetected);
}
 
void loop()
{
	pox.update();
	
	//get bpm
	Lcd_Init(0);
	Lcd_Position(0, 0, 0);
	Lcd_Prints(0, "BPM: ");
	char* temp;
	dtostrf(pox.getHeartRate(), 6, 2, temp);
	Lcd_Prints(0, temp);
	
	//get sp02
	Lcd_Position(0, 1, 0);
	Lcd_Prints(0, "SPO2: ");
	dtostrf(pox.getSpO2(), 6, 2, temp);
	Lcd_Prints(0, temp);
}

int main(){
	setup();
	while(1){
		loop();
	}
}

