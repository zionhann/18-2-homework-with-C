/*
 Course : C programming
 Section : 03
 Student ID: 21800779
 Name : Sion Han
 Discription: A programme processing 50 random numbers with 5 options.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void defineAry(int[], int[]);
int menu(void);
void rnTable(int[]);
void snList(int[]);
double stdev(int[]);
void searching(int[]);
void count(int[], int *, int *, int *);

int main(void)
{
    srand(time(NULL));
    
    int randomNum[50]={0};
    int stackNum[11]={0};
    int option, play=1;
    char invalidChar;
    
    defineAry(randomNum, stackNum);
    
    while(play)
    {
        int zero=0, onetofive=0, sixtoten=0;
        
        option=menu();
        
        switch(option)
        {
            case 1:
                rnTable(randomNum);
                putchar('\n');
                break;
                
            case 2:
                snList(stackNum);
                putchar('\n');
                break;
                
            case 3:
                printf("Standard deviation of random numbers is %.2lf\n", stdev(randomNum));
                putchar('\n');
                break;

            case 4:
                searching(randomNum);
                putchar('\n');
                break;
                
            case 5:
                count(stackNum, &zero, &onetofive, &sixtoten);
                printf("=============================\n");
                printf("The number of 0: %d\n", zero);
                printf("The total number of 1 to 5: %d\n", onetofive);
                printf("The total number of 6 to 10: %d\n", sixtoten);
                printf("=============================\n");
                putchar('\n');
                break;
                
            case 6:
                printf("Exit programme...\n");
                play=0;
                break;
                
            default:
                printf("Invalid option!\n");
                invalidChar=getchar();
                putchar('\n');
        }
    }
}

void defineAry(int rn[], int sn[])
{
    for(int i=0;i<50;i++)
    {
        rn[i]=rand()%11;
        
        switch(rn[i]) {
            case 0:
                sn[0]++;
                break;
            case 1:
                sn[1]++;
                break;
            case 2:
                sn[2]++;
                break;
            case 3:
                sn[3]++;
                break;
            case 4:
                sn[4]++;
                break;
            case 5:
                sn[5]++;
                break;
            case 6:
                sn[6]++;
                break;
            case 7:
                sn[7]++;
                break;
            case 8:
                sn[8]++;
                break;
            case 9:
                sn[9]++;
                break;
            case 10:
                sn[10]++;
        }
    }
    
}

int menu(void)
{
    int menu;
    
    printf("**************************************************\n");
    printf("** 1. 50 random numbers from 0 to 10.           **\n");
    printf("** 2. The number of each number.                **\n");
    printf("** 3. Standard deviation                        **\n");
    printf("** 4. Search numbers.                           **\n");
    printf("** 5. The total number of 0, 1 to 5, and 6 to 10**\n");
    printf("** 6. Exit.                                     **\n");
    printf("**************************************************\n");
    
    printf("Select menu<1~6>: " );
    scanf("%d", &menu);
    
    return menu;
}

void rnTable(int rn[])
{
    putchar('\n');
    
    for(int i=0;i<10;i++)
    {
        for(int j=0+5*i;j<5+5*i;j++)
            printf("%2d\t\t", rn[j]);
        
    putchar('\n');
    }
}

void snList(int sn[])
{
    for(int i=0;i<11;i++)
        printf("%2d: %2d\n", i, sn[i]);
}

double stdev(int rn[])
{
    int sum=0, mean;
    double numeSum=0, variance;
    
    for(int i=0;i<50;i++)
        sum+=rn[i];
    
    mean=sum/50;
    
    for(int i=0;i<50;i++)
        numeSum+=pow((rn[i]-mean), 2.0);
    
    variance=numeSum/49;
    
    return sqrt(variance);
}

void searching(int rn[])
{
    int inputNum;
    char invalidChar;
    
    do
    {
        printf("Enter the number you are looking for<0~10>: ");
        scanf("%d", &inputNum);
        
        if(inputNum>=0 && inputNum<=10)
        {
                for(int j=0;j<50;j++)
                    if(rn[j]==inputNum)
                        printf("a[%d]\t", j);
        }
        else
        {
            printf("Invalid Number!\n");
            invalidChar=getchar();
        }
    }
    while(!(inputNum>=0 && inputNum<=10));
}

void count(int sn[], int *zero, int *onetoFive, int *sixtoTen)
{
    *zero=sn[0];
    
    for(int i=1;i<=5;i++)
        *onetoFive+=sn[i];
    
    for(int i=6;i<=10;i++)
        *sixtoTen+=sn[i];
}
