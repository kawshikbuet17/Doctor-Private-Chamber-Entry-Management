//
// Created by mahdi on 7/5/2021.
//

#ifndef PROJCODES_STORE_H
#define PROJCODES_STORE_H

#include "../all.h"
struct storeRecords {
	char * name;
	unsigned int age;
	char * phone;
};
void Store_Init();
void Store_ProcessKey(int_fast8_t key);

#endif //PROJCODES_STORE_H
