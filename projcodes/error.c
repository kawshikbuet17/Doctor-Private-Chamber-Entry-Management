#include "all.h"

void Error_Error(const char * text)
{
	// HC05_SendString(text);
}
void Error_ErrorNum(const char * text , int val)
{
// 	HC05_SendString(text);
// 	char temp[10];
// 	sprintf(temp , " = %d\n" , val);
// 	HC05_SendString(temp);
// 	HC05_SendString("\r\n");
}
void Error_ErrorBin(const char * text,int val)
{
	// HC05_SendString(text);
	// char temp[10];
	// for(int i=0;i<8;i++)
	// 	temp[i]='0' + ((val>>i)&1);
	// temp[8]=0;
	// HC05_SendString(temp);
	// HC05_SendString("\r\n");
}