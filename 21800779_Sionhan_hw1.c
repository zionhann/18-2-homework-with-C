/*
과제1
작성자: 21800779 한시온 
작성일: 2018. 09. 01.
설명: 연결할 컴퓨터의 수를 입력받아 연결하는데 필요한 라인의 수를 
		수식을 통해 계산하는 프로그램. 
*/

#include <stdio.h>

int main(void)
{
	int num;
	printf("연결할 computer의 수를 입력: ");
	scanf("%d",&num);
	
	printf("총 필요한 line의 수: %d", num*(num-1)/2);
	
	return 0;
}
