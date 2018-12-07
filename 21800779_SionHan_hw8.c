/*
 Course : C programming
 Section : 03
 Student ID: 21800779
 Name : Sion Han
 Discription: A programme processing grades with 5 options.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void defineAry(float[][5], char[], int[]);
int menu(void);
void record(float[][5], char[]);
void chart(int[]);
void searching(float[][5], char[]);
void GPA(int[]);
void descOrder(float[][5], char[]);

int main(void)
{
    float floAry[30][5]={0};
    char chAry[30]={0};
    int intAry[5]={0};
    
    srand(time(NULL));
    int option, play=1;
    char linefeed;
    
    defineAry(floAry, chAry, intAry);
    
    while(play)
    {
        option=menu();
        
        switch(option)
        {
            case 'A':
                record(floAry, chAry);
                linefeed=getchar();
                putchar('\n');
                break;
                
            case 'B':
                chart(intAry);
                linefeed=getchar();
                putchar('\n');
                break;
                
            case 'C':
                searching(floAry, chAry);
                linefeed=getchar();
                putchar('\n');
                break;
                
            case 'D':
                GPA(intAry);
                linefeed=getchar();
                putchar('\n');
                break;
                
            case 'E':
                descOrder(floAry, chAry);
                linefeed=getchar();
                putchar('\n');
                break;
                
            case 'F':
                printf("Exit programme...\n");
                play=0;
                break;
                
            default:
                printf("Invalid option!\n");
                if(option!='\n') linefeed=getchar();
                putchar('\n');
        }
    }
}
void defineAry(float floAry[][5], char chAry[], int intAry[])
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<30;j++)
        {
            switch(i)
            {
                case 0:
                    floAry[j][0]=101+j;
                    break;
                    
                case 1: case 2:
                    floAry[j][i]=rand()%41+60; //60~100
                    break;
                    
                case 3:
                    floAry[j][3]=rand()%61+40; //40~100
                    break;
                    
                case 4:
                    floAry[j][4]=floAry[j][1]*0.2+floAry[j][2]*0.2+floAry[j][3]*0.6;
            }
        }
    }
    
    for(int j=0;j<30;j++)
        switch((int)floAry[j][4]/10)
    {
        case 10: case 9:
            chAry[j]='A';
            intAry[0]++;
            break;
            
        case 8:
            chAry[j]='B';
            intAry[1]++;
            break;
            
        case 7:
            chAry[j]='C';
            intAry[2]++;
            break;
            
        case 6:
            chAry[j]='D';
            intAry[3]++;
            break;
            
        default:
            chAry[j]='F';
            intAry[4]++;
    }
}

int menu(void)
{
    char menu;
    
    printf("***************MENU*******************************\n");
    printf("** A. Grades of all students.                   **\n");
    printf("** B. A distribution chart according to grades. **\n");
    printf("** C. Search Grades by ID.                      **\n");
    printf("** D. GPA.                                      **\n");
    printf("** E. Sorted grades in descending order.        **\n");
    printf("** F. Exit.                                     **\n");
    printf("**************************************************\n");
    
    printf("Select menu<A~F>:" );
    scanf("%c", &menu);
    
    return (menu>='a'&& menu<='z')? menu=toupper(menu) : menu;
}

void record(float ID_and_Score[][5], char grade[])
{
    printf("ID\tExam1\tExam2\tExam3\tScore\tGrade\n");
    printf("====================================================\n");
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<6;j++)
        {
            switch(j)
            {
                case 0:
                    printf("%.0f", ID_and_Score[i][0]);
                    putchar('\t');
                    break;
                case 1: case 2: case 3:
                    printf(" %.0f", ID_and_Score[i][j]);
                    (ID_and_Score[i][j]==100) ? putchar('\t') : printf("\t\t");
                    break;
                case 4:
                    printf(" %.1f", ID_and_Score[i][4]);
                    printf("\t");
                    break;
                case 5:
                    printf(" %c", grade[i]);
            }
        }
        putchar('\n');
    }
    printf("====================================================\n");
}

void chart(int count[])
{
    printf("========== Grade Distribution ==========\n");
    for(int i=0;i<5;i++)
    {
        printf("%c: ", (i==4)?'F':'A'+i);
        for(int j=0;j<count[i];j++)
            printf("* ");
        putchar('\n');
    }
    printf("=========================================\n");
}

void searching(float SCORE[][5], char GRADE[])
{
    int inputID;
    char invalidChar;
    
    do
    {
        printf("Enter the ID you are looking for<101~130>: ");
        scanf("%d", &inputID);
        
        if(inputID>=101 && inputID<=130)
        {
            printf("Score of ID %d: %.1f\n", inputID, SCORE[inputID-101][4]);
            printf("Grade of ID %d: %c\n", inputID, GRADE[inputID-101]);
        }
        else
        {
            printf("Invalid ID!\n");
            invalidChar=getchar();
        }
    }
    while(!(inputID>=101 && inputID<=130));
}

void GPA(int grade_count[])
{
    printf("GPA from ID 101 to ID 130 is %.1f\n",
           ((float)4*grade_count[0]+3*grade_count[1]+2*grade_count[2]+grade_count[3])/30);
}

void descOrder(float floAry[][5], char chAry[])
{
    float score[30][5]={0};
    char grade[30]={0}, chTemp;
    float floTemp;
    
    for(int i=0;i<30;i++) //copy
    {
        for(int j=0;j<5;j++)
            score[i][j]=floAry[i][j];
        grade[i]=chAry[i];
    }
    
    for(int i=0;i<30-1;i++)
    {
        for(int row=0;row<30-1;row++)
        {
            if(score[row][4]<score[row+1][4])
            {
                for(int column=0;column<5;column++)
                {
                    floTemp=score[row][column];
                    score[row][column]=score[row+1][column];
                    score[row+1][column]=floTemp;
                }
                chTemp=grade[row];
                grade[row]=grade[row+1];
                grade[row+1]=chTemp;
            }
        }
    }
    record(score, grade);
}
