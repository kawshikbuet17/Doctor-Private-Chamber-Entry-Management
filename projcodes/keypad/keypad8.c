#include "../all.h"

char keyBuffer[17];
bool isNumber = 0;
bool isUpperCase = 0;
int position =0;

void Keypad_Init()
{
	// col: b7-b0
	// row: a7-a4
	// cols will function as output, rows will as input
    DDRA = (DDRA & 0b00000011) | 0x00;
	DDRB = 0xFF;
	// PORTA = 0x00;       /** you may use 0b 0000 00XX if ADC has any operations after that. However, we are not reading that data for getting rows */
	PORTB = 0xFF;
}
void Keypad_ResetBuffer()
{
	isNumber = false;
	isUpperCase = false;
	position = 0;
	keyBuffer[position] = 0;
}

void Keypad_WriteToBuffer(char * newData)
{
	if(newData == NULL)
	{
		Error_Error("newData is Null");
		position = 0;
		keyBuffer[position]=0;
	}
	else 
	{
		int sz = min(strlen(newData),16);
		for(position=0;position<sz;position++)
			keyBuffer[position] = newData[position];
		keyBuffer[position] = 0;
	}
}

void Keypad_InitNumpad()
{
	isNumber = true;
}

const char * Keypad_GetMode()
{
	if(isNumber)
		return "123";
	else if(isUpperCase)
		return "ABC";
	else return "abc";
}

void Keypad_UpdateKeyMode()
{
	const char * s = Keypad_GetMode();
	Lcd_Position(LCDKEYPAD,0,16-strlen(s));
	Lcd_Prints(LCDKEYPAD,s);
}

inline int_fast8_t Keypad_KeyPressed()
{
	return (PINA >> 4);
}

int_fast8_t Keypad_GetRow()
{
	int pin = PINA >> 4;
	Error_ErrorBin("PIN_row:",pin);
	for(int i=0;i<4;i++)
	{
		if(pin&(1<<i))
			return i;
	}
	// report error
	Error_Error("KeypadGetRow:");
	return -1;
}

int_fast8_t Keypad_GetCol()
{
	int i = 7;
	while(i >=0)
	{
		PORTB = PORTB ^(1<<i);
		Error_ErrorBin("PINB:",PINB);
		if(!Keypad_KeyPressed())
		{
			return i;
		}
		i--;
	}
	Error_Error("KeypadGetCol:");
	// report error
	return -1;
}

void addChar(const char c)
{
	keyBuffer[position] = c;
	if(position < 16)
		position = position +1;
	keyBuffer[position] = 0;
	//HC05_SendString("keybuff:");
	//HC05_SendString(keyBuffer);
	//HC05_SendString(":\r\n");
	//char temp[10];
	//sprintf(temp , "pos:%d:\n",position);
	//HC05_SendString(temp);
}

void Keypad_AddKey(int_fast8_t key)
{
	if(key >= 30)
		Error_Error("KeyPad_AddKey: 31|30");
	if(key == 29) 
	{
		// backspace = delete char
		if(position)
			position--;
		keyBuffer[position] = 0;
	}
	else if(key == 28)
	{
		// space
		addChar(' ');
	}
	else if(key == 27)
	{
		// toggle num/abc
		isNumber = ! isNumber;
	}
	else if(isNumber) 
	{
		char row = key >> 3;
		char col = key & 0b00000111;
		char c;
		
		if(col >= 3) return;
		
		if(row < 3) {
			c = '1' + row * 3 + col;
		}
		else if(col == 0) {
			c = '*';
		}
		else if(col == 1) {
			c = '0';
		}
		else  {
			c = '#';
		}
		addChar(c);
		
	}
	else if(key == 26)
	{
		// capslock
		isUpperCase = !isUpperCase;
	}
	else
	{
		// char
		char row = key >> 3;
		char col = key & 0b00000111;
		char c;
		
		if(row < 3) {
			c = 'A' + (isUpperCase ? 0 : 32) + row * 8 + col;
		}
		else {
			c = 'Y' + (isUpperCase ? 0 : 32) + col;
		}
		
		addChar(c);
	}
	return ;
}

int_fast8_t Keypad_GetKey()
{
	int_fast8_t row = Keypad_GetRow();
	int_fast8_t col = Keypad_GetCol();
	Error_ErrorNum("row",row);
	Error_ErrorNum("col",col);
	return row * 8 + col;
}