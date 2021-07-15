#include "lcdgeneric.h"

void Lcd_Init(int_fast8_t lcdType)
{
	switch(lcdType)
	{
		case LCDKEYPAD:
			DDRD = DDRD | 0b11111100;
			Lcd4_Init();
			break;
		case LCDNOTICE:
			//////////////////////////////////////////////////////////////////////////
			//lcd with i2c
			lcd_init(LCD_ON_DISPLAY);
			lcd_backlight(0);
			_delay_ms(500);
			lcd_backlight(1);
			_delay_ms(500);
			lcd_clrscr();
			//////////////////////////////////////////////////////////////////////////
			break;
		default:
			Error_Error("Lcd_Init: LcdType Notsupported");
	}
}
void Lcd_ClearScreen(int_fast8_t lcdType)
{
	switch(lcdType)
	{
		case LCDKEYPAD:
			Lcd4_Clear();
			break;
		case LCDNOTICE:
			lcd_clrscr();
			break;
		default:
			Error_Error("Lcd_ClearScreen: LcdType Not supported");
	}
}
void Lcd_Prints(int_fast8_t lcdType ,const char * s)
{
	switch(lcdType)
	{
		case LCDKEYPAD:
			Lcd4_Write_String(s);
			break;
		case LCDNOTICE:
			lcd_puts(s);
			break;
		default:
			Error_Error("Lcd_ClearScreen: LcdType Not supported");
	}
}
void Lcd_Position(int_fast8_t lcdType,int x,int y)
{
	switch(lcdType)
	{
		case LCDKEYPAD:
			Lcd4_Set_Cursor(x,y);
		break;
		case LCDNOTICE:
			lcd_gotoxy(y,x);
		break;
		default:
			Error_Error("Lcd_Position: LcdType Not supported");
	}
}
void Lcd_Printc(int_fast8_t lcdType ,const char c)
{
	char s[] = {c,0};
	Lcd_Prints(lcdType , s);
}
void Lcd_PrintLine(int_fast8_t lcdType , int row , char * str)
{
	Lcd_Position(lcdType , row , 0);
	int i =0;
	while (str[i])
	{
		Lcd_Printc(lcdType , str[i++]);
	}
	while(i<16)
		Lcd_Printc(lcdType , ' '),i++;
}