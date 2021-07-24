#include "../all.h"

char disp[16] = "00000000000001";
char result[8] = "000001"; 

double m=0,c=0; // gradient and slope

double sumit(int data_points[],int length){
	 int i;
	 double sum=0;
	 for(int i=1;i<=length;i++)sum+=data_points[i];

	 return sum;
}

double xysum(int data_points[],int length){
	 int i;
	 double sum=0;
	 for(int i=1;i<=length;i++)sum+=(i)*data_points[i];

	 return sum;
}

void regression(int data_points[],double n){
	double squarex= (n)*(n+1)*(2*n+1)/6.0;
	double xbar = (n+1)/2.0;
	double ybar = sumit(data_points,n)/n;

	m=(xysum(data_points,n)- n*xbar*ybar)/( squarex - n*xbar*xbar );
	c=ybar-m*xbar;
}

int Bp_Read(char channel)
{
    int Ain,AinLow;
	
	ADMUX=ADMUX|(channel & 0x0f);	/* Set input channel to read */

	ADCSRA |= (1<<ADSC);		/* Start conversion */
	while(ADCSRA & (1<<ADIF)==0);	/* Monitor end of conversion interrupt */
	_delay_us(10);
	AinLow = (int)ADCL;		/* Read lower byte*/
	Ain = (int)ADCH*256;		/* Read higher 2 bits and 
					Multiply with weight */
	Ain = Ain + AinLow;				
	return(Ain);			/* Return digital value*/
}

void Bp_Init()
{
	DDRA &= ~2;
	ADCSRA = 0x87;			/* Enable ADC, fr/128  */
	ADMUX = 0x40;			/* Vref: Avcc, ADC channel: 0 */
    Lcd_ClearScreen(LCDKEYPAD);
}

void Bp_PrintBp()
{
	int i;
	int thresh=300;
	int count=0;
	int count2=0; //modified peak counting algo
	
	
	/*  timing data */
    double sampling_rate = 0.100 ;	   	// actually this is the _delay_ms val
    int time_limit = 10 ;  				 //in seconds
    int se=time_limit/(sampling_rate*2);
    int data_points[se+1];

	data_points[0]=0;
	/* /timing data */
	
	/* for debugging purposes -> h and l records the peaks */
	int h=0;
	int l=1023;
	
	char val[6]; //temporary variable for itoa

    for(i=0;i<time_limit/(sampling_rate*2);i++){	
		data_points[i+1]=Bp_Read(0);
		
		itoa(data_points[i+1],val,10);
        // Lcd_PrintLine(LCDKEYPAD, 0, "Measuring...");
		
		int k=16*(data_points[i+1]-200)/375;
		
		// char anim[16]="";
		
		// int h=0;
		// for(h=0;h<k;h++){
		// 	anim[h]='~';
		// }
		// itoa(k,val,10);
        // Lcd_Position(LCDKEYPAD, 1, 0);
        // Lcd_Prints(LCDKEYPAD, anim);

		_delay_ms(sampling_rate*1000);
	
	}

	regression(data_points,se);

	//recorded wave form
	for(i=0;i<time_limit/(sampling_rate*2);i++){	
		thresh=(i+2)*m+c;

		int a=data_points[i+1];//current value
		char temp[11]="";
		char ccount[3];

		if(a>h)h=a; //max peak
		if(a<l)l=a; //min peak
		
		if(a>thresh){
			count+=1; //peak counting]
			if(a>data_points[i] && a>data_points[i+2]){
				count2+=1;
			}
			
		}
	}

    itoa(count2*(60/time_limit),val,10);

	strcat(val," bpm");
	Lcd_PrintLine(LCDKEYPAD, 1, val);
}
