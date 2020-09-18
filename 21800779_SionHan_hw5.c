/*
	Course : C programming
	Section : 03
	Student ID : 21800779
	Name : Sion Han
	Discription : A memory game

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num1, num2, num3, seed1, seed2, seed3, playtime=1, correct=0;
	char choice, linefeed;
	
	srand(time(NULL));
	
	while(1)
	{
		printf("<The memory game>\n");
		printf("Remember following numbers.\n");
	
		seed1=rand()%10;
		printf("%d\t", seed1);
		
		seed2=rand()%10;
		printf("%d\t", seed2);
		
		seed3=rand()%10;
		printf("%d\t", seed3);
		
		sleep(2);
		putchar('\r');
		printf("Enter the digit you remembered:\n ");
		scanf("%d %d %d", &num1, &num2, &num3);
		
		if(num1==seed1 && num2==seed2 && num3==seed3) 
		{
			printf("Well done!\n");
			correct++;
		}
		
		else printf("Incorrect\n");
		
		printf("Play again?(y/n): ");
		linefeed=getchar();
		scanf("%c", &choice);
		
		if(choice=='y' || choice=='Y')
		{
			playtime++;
			putchar('\n');
		}
		
		else
		{
			printf("\nYou've got %d point(s) of all %d point(s)\n", correct, playtime);
			printf("Game Over...\n");
			break;
		}
	}
}
