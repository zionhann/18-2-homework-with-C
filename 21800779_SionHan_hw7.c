/*
 
 Course : C programming
 Section : 03
 Student ID : 21800779
 Name : Sion Han
 Discription : A random math quiz programme with three types of different levels.
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ON 1
#define OFF 0

int menu(void);
int check(int, int, int, int);
int keepgoing(void);

int main(void)
{
    int quiz=ON, replay=ON;
    int num[2]={0};
    char linefeed;
    srand(time(NULL));
    
    while(quiz)
    {
        char level=menu();
        int input=0, pass=0, tryagain=ON;
        
        do
        {
            switch(level)
            {
                case'L': case'l':
                    for(int i=0;i<2;i++) num[i]=rand()%9+1;
                    break;
                
                case 'm': case'M':
                    for(int i=0;i<2;i++) num[i]=rand()%90+10;
                    break;
                
                case'h': case'H':
                    for(int i=0;i<2;i++) num[i]=rand()%900+100;
                    break;
                
                case'Q': case'q':
                    printf("Exit programme...");
                    replay=OFF;
                    quiz=OFF;
                    continue;

                default:
                    printf("\nInvalid option!\n\n");
                    replay=OFF;
                    if(level!='\n') linefeed=getchar();
                    continue;
            }
            do
            {
                printf("%d + %d = ", num[0], num[1]);
                scanf("%d", &input);
        
                pass=check(input, num[0], num[1], tryagain);
                tryagain=pass;
                input=0;
            }
            while(!pass);
            
            if(keepgoing()) replay=ON;
            else
            {
                linefeed=getchar();
                replay=OFF;
            }
        }
        while(replay);
    }
}

int menu(void)
{
    char level;
    
    for(int i=1;i<70;i++) printf("*");
    putchar('\n');
    printf("*  L/l: Low level: A calculator consisting of 1 digit for add.     \t*\n");
    printf("*  M/m: Medium level: A calculator consisting of 2 digit for add.  \t*\n");
    printf("*  H/h: High level: A calculator consisting of 3 digit for add.    \t*\n");
    printf("*  Q/q: Quit: Exit programme.                                      \t*\n");
    for(int i=1;i<70;i++) printf("*");
    putchar('\n');
    
    printf("Select level: ");
    scanf("%c", &level);
    
    return level;
}

int check(int input, int x, int y, int tryagain)
{
    char invalidChar;
    
    if(input==x+y)
    {
        printf("Correct!\n");
        return ON;
    }
    else
    {
        if(input==0) invalidChar=getchar();
        printf("Incorrect!\n");
        
        if(tryagain==ON)
        {
            printf("Try again\n");
            return OFF;
        }
        else
        {
            printf("The right answer is %d\n", x+y);
            return ON;
        }
    }
}

int keepgoing(void)
{
    char YesorNo, linefeed;
    
    printf("Do you want to solve another problem?(y/n): ");
    linefeed=getchar();
    scanf("%c", &YesorNo);
    
    if(YesorNo=='y'|| YesorNo=='Y') return ON;
    else return OFF;
}

