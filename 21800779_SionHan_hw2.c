/*
����2
�ۼ���: 21800779 �ѽÿ� 
�ۼ���: 2018. 09. 07.
����: ��¥�� Ű, �����Ը� �Է¹ް� �̸�  
		�ٸ� ����(�Ǵ� ����)���� ��ȯ�Ͽ� ����ϴ� ���α׷�. 
*/
#include <stdio.h>

int main(void)
{
	int year, month, day;
	float height, weight;
	int feet;
	printf("Enter the Measurement Date<18/8/31> : ");
	scanf("%d/%d/%d", &year, &month, &day);
	
	printf("Enter the height in \"cm\" : ");
	scanf("%f" ,&height);
	feet=(height/2.54)/12;
	
	printf("Enter the weight in \"kg\" : ");
	scanf("%f", &weight);
	
	printf("\n<Conversion Program>");
	printf("\n===================================");
	printf("\nMeasurement Date : 20%.2d-%.2d-%.2d", year, month, day);
	printf("\nYour Height : %dfeet %.1finchs ", feet, ((height/2.54)/12-feet)*12);
	printf("\nYour Weight : %.2fpounds", weight/0.4535);
	printf("\n===================================\n");
	return 0;
	
	
}
