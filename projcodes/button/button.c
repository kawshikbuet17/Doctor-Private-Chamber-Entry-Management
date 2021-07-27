#include "button.h"

void Button_Init()
{
	DDRA &= ~(1<<2);
}
bool Button_ButtonPressed()
{
	return (((PINA>>2)&1) == 0);
}