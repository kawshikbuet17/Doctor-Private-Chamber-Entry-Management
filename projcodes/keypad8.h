#include <avr/io.h>
#include <util/delay.h>

unsigned int numLocked = 1;
unsigned int capsLocked = 0;


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

int_fast8_t Keypad_KeyPressed()
{
	return (PINA >> 4);
}

int_fast8_t Keypad_GetRow()
{
	int pin = PINA >> 4;
	for(int i=0;i<4;i++)
	{
		if(pin&(1<<i))
			return i;
	}
	// report error
	return -1;
}

int_fast8_t Keypad_GetCol()
{
	for(int i=0;i<8;i++)
	{
		PORTB = PORTB ^ (1<<i);
		if(!(Keypad_KeyPressed()))
		{
			return i;
		}
	}	
	// report error
	return -1;
}
/*
char KeyPad_getKey()
{
	int row = getRow();
   	_delay_ms(2);
	int col = getCol();
	unsigned char c = '';

	if(numLocked) {
		if(row < 3) {
			c = '1' + row * 3 + col;
		}
		else {
			if(col == 0) {
				c = '*';
			}
			else if(col == 1) {
				c = '0';
			}
			else if(col == 2) {
				c = '#';
			}
		}
	}

	else {
		if(row < 3) {
			c = 'A' + (capsLocked ? 0 : 32) + row * 8 + col;
		}
		else {
			if(col == 0 || col == 1) {
				c = 'Y' + (capsLocked ? 0 : 32) + col;
			}
			else if(col == 2) {
				capsLocked = !capsLocked;
				lcd_cursor_pos--;
			}
			else if(col == 3) {
				numLocked = !numLocked;
				lcd_cursor_pos--;
			}
			else if(col == 4) {
				// whitespace
				lcd_cursor_pos++;
			}
			else if(col == 5) {
				// backspace
				lcd_cursor_pos -= 2;
			}
			else if(col == 6) {
				// codes for PREV 
			}
			else if(col == 7) {
				// codes for NEXT
			}
		}
	}

	lcd_cursor_pos ++;
	return c;
}
*/
int_fast8_t Keypad_GetKey()
{
	int_fast8_t row = Keypad_GetRow();
	int_fast8_t col = Keypad_GetCol();
	return row * 8 + col;
}