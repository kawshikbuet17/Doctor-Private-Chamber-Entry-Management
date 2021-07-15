//
// Created by mahdi on 7/5/2021.
//

#ifndef INFORMATION_H_ADDED
#define INFORMATION_H_ADDED

#include "../all.h"


struct Patient {
	char name [17];
	char age [17];
	char phone [17];
	int serial ;
};

void Patient_UpdateName(struct Patient *p, char *newName);
void Patient_UpdateAge(struct Patient *p, char *newAge);
void Patient_UpdatePhone(struct Patient *p, char *newPhone);
extern struct Patient currentPatient;
#endif //INFORMATION_H_ADDED
