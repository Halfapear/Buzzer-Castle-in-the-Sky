#include <REGX52.H>
#include "Delay.h"
#include "Time0.h"
#include "Buzzer.h"
 
//蜂鸣器端口：
sbit Buzzer=P2^5;
 
#define SPEED 460
//音符与索引对应表，P：休止符，L：低音，M：中音，H：高音，下划线：升半音符号#
#define P	0
#define L1	1
#define L1_	2
#define L2	3
#define L2_	4
#define L3	5
#define L4	6
#define L4_	7
#define L5	8
#define L5_	9
#define L6	10
#define L6_	11
#define L7	12
#define M1	13
#define M1_	14
#define M2	15
#define M2_	16
#define M3	17
#define M4	18
#define M4_	19
#define M5	20
#define M5_	21
#define M6	22
#define M6_	23
#define M7	24
#define H1	25
#define H1_	26
#define H2	27
#define H2_	28
#define H3	29
#define H4	30
#define H4_	31
#define H5	32
#define H5_	33
#define H6	34
#define H6_	35
#define H7	36
unsigned int FreqTable[] = {0,
	64303 ,63577 ,63691 ,63792 ,63892 ,63981 ,64070 ,64152 ,64229 ,64303 ,64372 ,64437 ,
	64499 ,64557 ,64612 ,64664 ,64713 ,64759 ,64803 ,64844 ,64883 ,64919 ,64954 ,64987 ,
	65018 ,65047 ,65074 ,65100 ,65125 ,65148 ,65169 ,65190 ,65209 ,65228 ,65245 ,65261
};
 
 
// 第一个H2意思是频率；第二个4，代表一个4分音符；code是把代码放到Flash里面。
unsigned char code Music[]={
	H2,4,
	M7,4,
	H1,4,
	M6,4,
	
	H2,4,
	M7,4,
	H1,4,
	M6,4,
//	// 注释部分是高潮的前面部分
//	M3,4+4+4+4,
//	P,4+4,	
//	P,2,	
//	M1,2,
//	M2,2,
//	M1,2,
//	M3,4+4+4+4,
//	P,4+2,
//	M1,2,
//	M2,2,
//	M1,2,
//	M2,2,
//	M3,2,
//	//
//	L6,4+2,
//	M1,2,
//	L6,4+2,
//	M1,2,
//	
//	L6,4+2,
//	M1,2,
//	M2,4,
//	M1,4,
//	
//	L7,4+4+4+4,
//	P,4+4+4+4,
//	
//	//
//	M3,4+4+4+4,
//	P,4+4,	
//	P,2,	
//	M1,2,
//	M2,2,
//	M1,2,
//	M3,4+4+4+4,
//	P,4+2,
//	M1,2,
//	M2,2,
//	M1,2,
//	M2,2,
//	M3,2,
//	//
//	L6,4+2,
//	M1,2,
//	L6,4+2,
//	M1,2,
//	
//	L6,4+2,
//	M1,2,
//	M3,4,
//	M1,2,
//	M2,2,
//	
//	L7,4+4+4+4,
//	P,4+4+4+4,
	//
//	H6,2,
//	M1,2,
//	M6,4+2+2+2,
//	M5, 2,
//	
//	M6,4+2,
//	M5,2,
//	M6,2,
//	M5,2,
//	M6,2,
//	
//	M5,2+2,
//	M3,2+2+4+4,
//	P,4+4+4,
//	H6,2,
//	M1,2,
	//
//	M6,4+2+2,
//	M5,2,
//	M6,2,
//	M5,2,
 
//	M7,4+2+2,
//	M6,2,
//	M7,2+2,
//	M6,4,
//	M3,2+2+4,
//	
//	P,4+4+2,
//	M3,2,
//	M5,2,
//	M3,2,
	//
//	M2,4+2,
//	M3,2,
//	M2,4+2,
//	M3,2,
 
//	M2,4+2,
//	M3,2,
//	M5,2,
//	M3,2,
//	M5,2,
//	M3,2,
//	
//	M2,4+2,
//	M3,2,
//	M2,4+2,
//	M3,2,
//	
//	M2,4+4+4,
//	M1,2,
//	M2,2,
//	//
//	M3,4,
//	M6,4,
//	M1,4,
//	M3,2,
 
//	M2,4+2,
//	M3,2,
//	M2,4,
//	M1,4,
	
//	M6,4+4+4+4,
 
 
 
 
 
// 高潮部分
	P,4+4+4,
	M6,2,
	M7,2,
	//
	M1,2,
	M2,2,
	M7,2,
	M1,2+4+2,
	M7,2,
	
	M1,2,
	M2,2,
	M7,2,
	M1,2+4+2,
	M2,2,
	
	M3,2,
	M2,2,
	M3,2,
	M2,2,
	M3,4+2,
	M2,2,
	
	M3,4,
	M5,4,
	M3,4,
	M6,2,
	M7,2,
	//
	M1,2,
	M2,2,
	M7,2,
	M1,2+4+2,
	M7,2,
	
	M1,2,
	M2,2,
	M7,2,
	M1,2+4+2,
	M2,2,
	
	M3,2,
	M2,2,
	M3,2,
	M2,2,
	M3,4+2,
	M2,2,
	
	M3,4,
	M5,4,
	M3,4,
	M5,4,
	//
	M3,2+4,
	M5,2,
	M3,2+4,
	M5,2,
	
	M3,2,
	M5,2,
	M6,2,
	M3,2,
	M5,4,
	M5,4,
	
	M3,2+4,
	M5,2,
	M3,2+4,
	M5,2,
//	
	M3,2,
	M5,2,
	M6,2,
	M3,2,
	M5,4,
	M5,2+2,
//
	M3,4,
	M2,4,
	M2,4,
	M1,2,
	M3,2,
	
	M3,4,
	M2,4,
	M2,4,
	M1,2,
	M1,2,
	
	L6,4+4+4+4,
	P,4+4+4,
	M5,2+2,
 
	//
	M3,4,
	M2,4,
	M2,4,
	M1,2,
	M3,2,
	
	M3,4,
	M2,4,
	M2,4,
	M1,2,
	M1,2,
	
	L6,4+4+4+4,
	P,4+4+4+4,
	
	0xFF
};
	
 
 
 
unsigned char FreqSelect,MusicSelect;
void main(){
	// 初始化定时器
	Timer0Init();
	while(1){
		// 判断是否是休止符
		if(Music[MusicSelect] != 0xFF){
			//发声
		FreqSelect = Music[MusicSelect];
		MusicSelect++;
			//持续时长
		Delay(SPEED/4*Music[MusicSelect]);
		MusicSelect++;
		TR0 = 0;
		Delay(5);
		TR0 = 1;
		}else{
			TR0 = 0;
		while(1);
	}
	}
		
	}
 
 
void Timer0_Routine() interrupt 1
{
if(FreqTable[FreqSelect]){
	TL0 = FreqTable[FreqSelect] % 256;		//设置定时初始值
	TH0 = FreqTable[FreqSelect] / 256;	
	Buzzer =! Buzzer; // 响
}
		
	}