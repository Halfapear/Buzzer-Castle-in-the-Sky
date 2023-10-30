#include <REGX52.H>

 
/**
  * @brief 定时器0初始化， 1毫秒@11.0592MHz
  * @param  无
  * @retval 无
  */

void Timer0Init(void)		//1毫秒@11.0592MHz
{
	// AUXR &= 0x7F;			//定时器时钟12T模式（调的时候已经设置了，这个就别写了）
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0xB0;				//设置定时初始值
	TH0 = 0x3C;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	ET0 = 1;
	EA = 1;
 	PT0 = 0;
}

//void Timer0_Init(void)		//1毫秒@11.0592MHz (从stcisp上调的，频率时长定时器应该都没问题，不能确定的只有模式和时钟)
//{
//	AUXR |= 0x80;			//定时器时钟1T模式
//	TMOD &= 0xF0;			//设置定时器模式
//	TL0 = 0xCD;				//设置定时初始值
//	TH0 = 0xD4;				//设置定时初始值
//	TF0 = 0;				//清除TF0标志
//	TR0 = 1;				//定时器0开始计时
//}

//void Timer0Init(void)		//1毫秒@11.0592MHz (csdn给的)
//{
// 
//	TMOD &= 0xF0;		//设置定时器模式
//	TL0 = 0xCD;		//设置定时初始值
//	TH0 = 0xD4;		//设置定时初始值
//	TF0 = 0;		//清除TF0标志
//	TR0 = 1;		//定时器0开始计时
//	ET0 = 1;
//	EA = 1;
//	PT0 = 0;
//}
 
/*
// 计时器0中断之后运行的函数
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0xCD;		//设置定时初始值
	TH0 = 0xD4;	
	T0Count++;
	if(T0Count >= 1000){
	T0Count = 0;		
	P2_0 = ~P2_0;
	Delay(100);
		
	}
}
*/