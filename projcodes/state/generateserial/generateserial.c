//
// Created by mahdi on 7/5/2021.
//

#include "../../all.h"


void GenerateSerial_Init()
{
    Lcd_ClearScreen(LCDKEYPAD);
	Lcd_Position(LCDKEYPAD,0,0);
	Lcd_Prints(LCDKEYPAD,"Your Serial: ");
	Update_Serial();
	Lcd_Position(LCDKEYPAD,1,0);
	Lcd_Prints(LCDKEYPAD,"N:Confirm P:Back");
}

void GenerateSerial_ProcessKey(int_fast8_t key)
{
	if(key == 31)
	{
		Lcd_ClearScreen(LCDKEYPAD);
		Lcd_Position(LCDKEYPAD,0,3);
		patientsCount++;
		Lcd_Prints(LCDKEYPAD,"Thank You");
		_delay_ms(2000);
		
		States_GotoState(IDLE);
		Clear_CurrentPatient_Data();
	}
	else if(key == 30)
	{
		States_GotoState(ENTERING_PHONE);
	}
	else 
	{
		
	}
}

void Update_Serial()
{
	char s[100];
	dtostrf((float)(patientsCount+1), 3, 0, s);
	Lcd_Position(LCDKEYPAD,0,13);
	Lcd_Prints(LCDKEYPAD,s);
	Patient_UpdateSerial(&currentPatient, patientsCount);
	Update_PatientsList();
}

void Update_PatientsList()
{
	struct Patient *cp = (struct Patient*) malloc(sizeof(struct Patient));
	strcpy(cp->name, currentPatient.name);
	strcpy(cp->age, currentPatient.age);
	strcpy(cp->phone, currentPatient.phone);
	cp->serial = currentPatient.serial;
	strcpy(cp->temperature, currentPatient.temperature);
	strcpy(cp->bp, currentPatient.bp);
	enqueue(cp);	
}

void Clear_CurrentPatient_Data(){
	strcpy(currentPatient.name, "");
	strcpy(currentPatient.age, "");
	strcpy(currentPatient.phone, "");
	strcpy(currentPatient.temperature, "");
	strcpy(currentPatient.bp, "");
}