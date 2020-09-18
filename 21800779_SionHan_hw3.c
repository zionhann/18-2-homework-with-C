/*
과제3
작성자: 21800779 한시온 
작성일: 2018. 09. 12.
설명: 	금액을 입력받아 단위에 맞게 출력하고 이를
		USD로 환산하여 dollar와 cent로 표시하는 프로그램. 
		 
*/

#include <stdio.h>
#define USD 1172.0

int main(void)
{
	int amount, dollar;
	int MAN, CHEON, BAEK, SIP, WON;
	
	printf("금액을 입력 : "); //12345
	scanf("%d", &amount);
	
	MAN= amount/10000;
	CHEON= (amount%10000-amount%1000)/1000;
	BAEK= (amount%1000-amount%100)/100;
	SIP= (amount%100-amount%10)/10;
	WON= amount%10;
	printf("\n입력된 금액은 총 %d만 %d천 %d백 %d십 %d원입니다.\n", MAN, CHEON, BAEK, SIP, WON);
	
	dollar= amount/USD;
	printf("\ndollar로 환산한 금액은 총 %ddollar %.0fcent\n", dollar, (amount/USD-dollar)*100);

	return 0;	
}
