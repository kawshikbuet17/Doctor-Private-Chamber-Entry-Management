/*
 * GccApplication1.c
 *
 * Created: 7/4/2021 4:14:07 PM
 * Author : mahdi
 */ 

#include "all.h"

struct Queue
{
	struct Patient queue[10];
	int maxsize;
	int front_num;
	int rear_num;
	int toq;
};

struct Queue q;

void Queue_Init(struct Queue *qptr)
{
	//toq=0;
	qptr->front_num = 0;
	qptr->rear_num = -1;
}

bool empty(struct Queue *qptr)
{
	if(qptr->front_num > qptr->rear_num)
		return true;
	else
		return false;
}

int size(struct Queue *qptr)
{
	return qptr->rear_num - qptr->front_num + 1 ;
}

void enqueue(struct Queue *qptr, struct Patient x)
{
	if(empty(&q))
	{
		
		Lcd_PrintLine(LCDNOTICE , 0 , "Patients are Wai");
		Lcd_PrintLine(LCDNOTICE , 1 , "ting use button");
		
	}
	qptr->queue[++qptr->rear_num] = x;
}

struct Patient* dequeue(struct Queue *qptr)
{
	struct Patient* value;
	if(empty(qptr))
	{
		return NULL;
	}
	
	value = &qptr->queue[qptr->front_num++];

	return value;
}

struct Patient* front(struct Queue *qptr)
{
	if(!empty(qptr))
	return &qptr->queue[qptr->front_num];
	else
	return NULL;
}
struct Patient* rear(struct Queue *qptr)
{
	if(!empty(qptr))
	return &qptr->queue[qptr->rear_num];
	else
	return NULL;

}

int currentPatientSerial(struct Queue *qptr)
{
	return front(qptr)->serial;
}

int nextPatientSerial(struct Queue *qptr)
{
	return qptr->queue[qptr->front_num + 1].serial;
}

bool doctorSeeing = 0;

int main(void)
{
	Queue_Init(&q);
	
	HC05_Init_Data_Mode();
	//HC05_Init_ATCommand_Mode();
	
	HC05_SendString("hello there");
	
	Lcd_Init(LCDKEYPAD);
	Lcd_Init(LCDNOTICE);
	
	Lcd_Position(LCDNOTICE , 0,0);
	Lcd_Prints(LCDNOTICE , "abcdefghijklmnopqrstuvwxyz");
	Lcd_Position(LCDNOTICE , 0,0);
	Lcd_Prints(LCDNOTICE , "abcdefghijklmnopqrstuvwxyz");
	Lcd_Prints(LCDNOTICE , "abcdefghijklmnopqrstuvwxyz");
	
	States_GotoState(IDLE);
	//States_GotoState(GENERATE_SERIAL);
	States_GotoState(ENTERING_BP);
	
	Keypad_Init();
	Button_Init();
	
	Lcd_PrintLine(LCDNOTICE , 0,"No Patient in ");
	Lcd_PrintLine(LCDNOTICE , 1,"the queue");
	
	while (1)
	{
		if(Keypad_KeyPressed())
		{
			_delay_ms(20);
			if(Keypad_KeyPressed())
			{
				int_fast8_t x = Keypad_GetKey();
				KeyProcessor_ProcessKey(x);
				_delay_ms(20);
				Keypad_Init();
			}
		}
		States_Refresh();
		if(Button_ButtonPressed())
		{
			// buzzer
			
			if(doctorSeeing)
			{
				
				if(empty(&q))
				{
					Lcd_PrintLine(LCDNOTICE , 0,"No Patient in ");
					Lcd_PrintLine(LCDNOTICE , 1,"the queue");
					doctorSeeing = 0;
				}
				else 
				{
					struct Patient* now =  front(&q);
					char s[17];
					sprintf(s,"%2d-%13s",now->serial , now->name);
					Lcd_PrintLine(LCDNOTICE , 0,s);
					sprintf(s,"%6sF%3sBPM%2sY",now->temperature,now->bp,now->age);
					Lcd_PrintLine(LCDNOTICE , 1,s);
					dequeue(&q);// ager ta falailam
				}
				
			}
			else
			{
				if(empty(&q))
				{
					;
				}
				else 
				{
					doctorSeeing = 1;
					
					struct Patient* now =  front(&q);
					char s[17];
					sprintf(s,"%2d-%13s",now->serial , now->name);
					Lcd_PrintLine(LCDNOTICE , 0,s);
					sprintf(s,"%6sF%3sBPM%2sY",now->temperature,now->bp,now->age);
					Lcd_PrintLine(LCDNOTICE , 1,s);
					dequeue(&q);// ager ta falailam
				}
			}
		}
		_delay_ms(100);
	}
}