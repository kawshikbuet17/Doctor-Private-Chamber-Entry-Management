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

		/* Here, can first prompt for providing temperature through lm and then go to the idle state for next entry */
		
		States_GotoState(IDLE);
		Clear_CurrentPatient_Data();
	}
	else if(key == 30)
	{
		States_GotoState(ENTERING_PHONE);	// if re-editing is permitted
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
	struct Patient *cp = (struct Patient*) malloc(sizeof(struct Patient));	//didn't wanna change your code, so created a new pointer
	strcpy(cp->name, currentPatient.name);
	strcpy(cp->age, currentPatient.age);
	strcpy(cp->phone, currentPatient.phone);
	cp->serial = currentPatient.serial;
	cp->nextPatient = NULL;
	strcpy(cp->temperature, currentPatient.temperature);
	strcpy(cp->bp, currentPatient.bp);
	if(!patientsList.root) {
		patientsList.root = cp;
	}
	else {
		struct Patient* p = patientsList.root;
		while(p->nextPatient) {
			p = p->nextPatient;
		}
		p->nextPatient = cp;
	}
	
}

void Clear_CurrentPatient_Data(){
	strcpy(currentPatient.name, "");
	strcpy(currentPatient.age, "");
	strcpy(currentPatient.phone, "");
	strcpy(currentPatient.temperature, "");
	strcpy(currentPatient.bp, "");
}