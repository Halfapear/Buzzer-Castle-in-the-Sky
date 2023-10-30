#include <REGX52.h>
//#include "Key.h"
//#include "Nixie.h"
//#include "Buzzer.h"
#include "Delay.h"
#include "Timer0.h"

sbit Buzzer=P2^5;

unsigned int FreqTable[]={
	0,
	63628,63731,63835,63928,64021,64103,64185,64260,64331,64400,64463,64528,
	64580,64633,64684,64732,64777,64820,64860,64898,64934,64968,65000,65030,
	65058,65085,65110,65134,65157,65178,65198,65217,65235,65252,65268,65283,
};

unsigned char FreqSelect;

void main(){
	Timer0Init();
	while(1){
		FreqSelect++;
		Delay(500);
	}
}

void Timer0_Routine() interrupt 1
{
	TL0 = FreqTable[FreqSelect]%256;
	TH0 = FreqTable[FreqSelect]/256;
	Buzzer = !Buzzer;
}

//sbit Buzzer = P1^5;
//void main(){
//	Timer0Init();
//	while(1){
//	}
//}
//	
//void Timer0_Routine() interrupt 1
//{
//	static unsigned int T0Count;
//	TL0 = 0xCD;		//???????
//	TH0 = 0xD4;	
//	Buzzer=!Buzzer;}