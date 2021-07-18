//
// Created by mahdi on 7/5/2021.
//

#include "../all.h"

struct Patient currentPatient ;
struct PatientsList patientsList;
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