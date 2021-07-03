#include <avr/io.h>
#include <util/delay.h>

unsigned int numLocked = 1;
unsigned int capsLocked = 0;

int lcd_cursor_pos = -1;  // may be an extern integer

void Keypad_Init()
{
	// col: b7-b4, a7-a4
	// row: a3b2b1b0
	// cols will function as output, rows will as input
	DDRA = 0xF0;
	DDRB = 0xF0;
	PORTA = 0xF0;
	PORTB = 0xF0;
}

int getRow()
{
	int row = 0, r;
	for(int i = 0; i < 4; i++) {
		r = (PINA & (1<<3)) | (PINB & 7);
		if(r & (1 << i)) {
			row = i;
			break;
		}
	}
	return row;
}

int getCol()
{
	int col = 0, r;
	DDRA = 0x08;	// reverting roles
	DDRB = 0x0F;

	for(int i = 0; i < 8; i++) {
		r = (PINA & 0xF0) | ((PINB & 0xF0) >> 4);
		if(r & (1 << i)) {
			col = i;
			break;
		}
	}

	Keypad_Init();
	return col;
}

char KeyPad_getKey()
{
	int row = getRow();
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
				/* codes for PREV */
			}
			else if(col == 7) {
				/* codes for NEXT */
			}
		}
	}

	lcd_cursor_pos ++;
	return c;
}
