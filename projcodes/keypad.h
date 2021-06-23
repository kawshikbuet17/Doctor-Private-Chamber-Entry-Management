


void Keypad_Init()
{
	// col in b7-b4 
	// row in b3-b0
	// col is output [0,1 controlled by atmega] , row is input [0,1 controlled by user]
	DDRB = 0b11110000;
	PORTB = 0b11110000;
}

char Keypad_Get_Key()
{
	int_fast8_t row = 0;
	for(int_fast8_t i = 0; i<4 ; i++)
		if((PINB >> i ) & 1 )
		{
			row = i;
			break;
		}
	
	int_fast8_t col = 0;
	// assumes PORTB = 0b1111xxxx;
	for(int_fast8_t i=16;i<256;i<<=1)
	{
		PORTB ^= i;
		if(!(PINB & 0b00001111))
		{
			break;
		}
		col++;
	}
	Keypad_Init();
	return row * 4 + col;
	
}