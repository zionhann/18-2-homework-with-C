/*
����3
�ۼ���: 21800779 �ѽÿ� 
�ۼ���: 2018. 09. 12.
����: 	�ݾ��� �Է¹޾� ������ �°� ����ϰ� �̸�
		USD�� ȯ���Ͽ� dollar�� cent�� ǥ���ϴ� ���α׷�. 
		 
*/

#include <stdio.h>
#define USD 1172.0

int main(void)
{
	int amount, dollar;
	int MAN, CHEON, BAEK, SIP, WON;
	
	printf("�ݾ��� �Է� : "); //12345
	scanf("%d", &amount);
	
	MAN= amount/10000;
	CHEON= (amount%10000-amount%1000)/1000;
	BAEK= (amount%1000-amount%100)/100;
	SIP= (amount%100-amount%10)/10;
	WON= amount%10;
	printf("\n�Էµ� �ݾ��� �� %d�� %dõ %d�� %d�� %d���Դϴ�.\n", MAN, CHEON, BAEK, SIP, WON);
	
	dollar= amount/USD;
	printf("\ndollar�� ȯ���� �ݾ��� �� %ddollar %.0fcent\n", dollar, (amount/USD-dollar)*100);

	return 0;	
}
