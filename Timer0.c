#include <REGX52.H>
#include <Delay.H>

 
/**
  * @brief 定时器0初始化， 1毫秒@11.0592MHz
  * @param  无
  * @retval 无
  */
void Timer0Init(void)		//1毫秒@11.0592MHz
{
 
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0xCD;		//设置定时初始值
	TH0 = 0xD4;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}
 
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