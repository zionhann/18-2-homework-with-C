/*
과제2
작성자: 21800779 한시온 
작성일: 2018. 09. 07.
설명: 날짜와 키, 몸무게를 입력받고 이를  
		다른 형식(또는 단위)으로 변환하여 출력하는 프로그램. 
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
