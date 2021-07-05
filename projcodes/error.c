#include "all.h"

void Error_Error(const char * text)
{
	HC05_SendString(text);
}
void Error_ErrorNum(const char * text , int val)
{
	HC05_SendString(text);
	char temp[10];
	sprintf(temp , " = %d\n" , val);
	HC05_SendString(temp);
}