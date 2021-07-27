//
// Created by mahdi on 7/5/2021.
//

#include "../all.h"

struct Patient currentPatient ;
int patientsCount = 0;

void Patient_UpdateName(struct Patient * p, char *newName)
{
	strcpy(p->name , newName);
}
void Patient_UpdateAge(struct Patient *p, char *newAge)
{
	strcpy(p->age , newAge);
}
void Patient_UpdatePhone(struct Patient *p, char *newPhone)
{
	strcpy(p->phone , newPhone);
}
void Patient_UpdateSerial(struct Patient *p, int newSerial)
{
	p->serial = newSerial;
}
void Patient_UpdateTemperature(struct Patient *p, char *newTemp)
{
	strcpy(p->temperature , newTemp);
}
void Patient_UpdateBp(struct Patient *p, char *newBp)
{
	strcpy(p->bp, newBp);
}