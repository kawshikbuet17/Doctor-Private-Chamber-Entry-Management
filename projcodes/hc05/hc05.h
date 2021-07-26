
#ifndef HC05_ADDED
#define HC05_ADDED

// pinout description https://components101.com/wireless/hc-05-bluetooth-module
void HC05_Init_Data_Mode(); // init data mode in hc05 , Data Mode Baud Rate: 9600, 8, N, 1
char HC05_ReceiveChar(); // read char from 
void HC05_SendChar(char); // 
void HC05_SendString(char *);
void HC05_Init_ATCommand_Mode();
#endif