/*
 * GccApplication1.c
 *
 * Created: 7/4/2021 4:14:07 PM
 * Author : mahdi
 */ 

#include "all.h"

int main(void)
{
	
	Lcd_Init(LCDKEYPAD);
	Lcd_Init(LCDNOTICE);	
	Keypad_Init();
	
	Lcd_Prints(LCDKEYPAD , "starting");
	Lcd_Position(LCDKEYPAD , 0,0);
	
	HC05_Init_ATCommand_Mode();
	//HC05_Init_Data_Mode();
	_delay_ms(500);
	
	Lcd_ClearScreen(LCDKEYPAD);
	
	Lcd_Prints(LCDKEYPAD , "re:");
	
	while (1)
	{
		if(HC05_ReceiveAvailable())
		{
			char s[20];
			int i=0;
			while (HC05_ReceiveAvailable() && i<20)
			{
				s[i++] =  HC05_ReceiveChar();
			}
			for(int j=0;j<i;j++)
				Lcd_Printc(LCDKEYPAD , s[j]);
		}
		
		if(Keypad_KeyPressed())
		{
			_delay_ms(20);
			if(Keypad_KeyPressed())
			{
				char s[20];
				int_fast8_t x = Keypad_GetKey();
				if(x==0) strcpy(s,"AT\r\n"); //a
				else if(x==1) strcpy(s,"AT+ROLE=2\r\n");//b
				else if(x==2) strcpy(s,"AT+RESET\r\n");//c
				else if(x==3) strcpy(s,"AT+VERSION?\r\n");//d
				else if(x==4) strcpy(s,"AT+ORGL\r\n");//e
				else if(x==5) strcpy(s,"AT+ADDR?\r\n");//f
				else if(x==6) strcpy(s,"AT+NAME?\r\n");//g
				else if(x==7) strcpy(s,"AT+ROLE?\r\n");//h
				else if(x==8) strcpy(s,"AT+ROLE=0\r\n");//i
				else if(x==9) strcpy(s,"AT+ROLE=1\r\n");//j
				else if(x==10) strcpy(s,"AT+PSWD?\r\n");//k
				else if(x==11) strcpy(s,"AT+UART?\r\n");//l
				else if(x==12) strcpy(s,"AT+UART?\r\n");//m
				else if(x==13) strcpy(s,"AT+UART=9600,0,0\r\n");//n
				else if(x==14) strcpy(s,"AT+UART=38400,0,0\r\n");//o
				else if(x==15) strcpy(s,"AT+BIND?\r\n");//p
				else if(x==16) strcpy(s,"AT+RMAAD\r\n");//q
				else if(x==17) strcpy(s,"AT+STATE?\r\n");//r
				else if(x==18) strcpy(s,"AT+NAME=HC-05\r\n");//s
				else if(x==19) strcpy(s,"AT+PSWD=1234\r\n");//t
				else if(x==20) strcpy(s,"AT+HELP\r\n");//u
				else if(x==21) strcpy(s,"AT+ROLE=2\r\n");//v
				else 
				{
					strcpy(s,"no");
				}
				
				Lcd_ClearScreen(LCDKEYPAD );
				Lcd_Position(LCDKEYPAD , 0, 0 );
				if(s[0]=='A')
					HC05_SendString(s);
				Lcd_Prints(LCDKEYPAD , s);
				Lcd_Position(LCDKEYPAD , 1 , 0);
				_delay_ms(500);
			}
			Keypad_Init();
		}
	}
}
