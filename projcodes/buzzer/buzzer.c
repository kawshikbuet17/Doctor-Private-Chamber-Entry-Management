#include "buzzer.h"

void Buzzer_Sound()
{
	int ms = 1000;
	DDRC |= (1<<2);
	int tot = 8;
	
	for(int i=0;i<tot;i++)
	{
		PORTC |= (1<<2);
		_delay_ms(ms/tot/2);
		PORTC &= ~(1<<2);
		_delay_ms(ms/tot/2);
	}
	Error_Error("buz");
}
