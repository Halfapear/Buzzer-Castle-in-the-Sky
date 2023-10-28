#include <REGX52.h>
#include "Key.h"
#include "Nixie.h"
#include "Buzzer.h"
#include "Delay.h"
char KeyNum;
void main(){
	Nixie(1,0);
	while(1){
		KeyNum= Key();
		if (KeyNum){
			Buzzer_Time(110);
			Nixie(1,KeyNum);
		}
}
}