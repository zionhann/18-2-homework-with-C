/*
 Course : C programming
 Section : 03
 Student ID: 21800779
 Name : Sion Han
 Discription: A programme managing at most 20 members with 5 options.
 */
#include <stdio.h>
#include <stdlib.h> //srand()
#include <time.h> //time()
#include <ctype.h> //toupper()
#include <string.h> //strcasecmp(), strlen(), strcmp()

typedef struct members
{
    char ID[7];
    char name[15];
    int workingHour;
    int hourlyWage;
    float totalPay;
}MEMBERS;

int menu(void);
void memTable(MEMBERS[]); //A
void memSearch(MEMBERS[]); //B
void ASCE(MEMBERS[]); //C
void total(MEMBERS[]); //D
void add(MEMBERS[]); //E

int checkDgt(MEMBERS[]);
void capID(MEMBERS[]);
int checkDup(MEMBERS[]);
void capName(MEMBERS[]);

static int g_count=10;

int main(int argc, char *argv[])
{
    FILE *data, *output;
    
    MEMBERS fData[20];
    
    data=fopen(argv[1], "r");
    while(!feof(data))
        for(int i=0;i<g_count;i++)
            fscanf(data, "%s\t%s\t%d\t%d", fData[i].ID, fData[i].name, &fData[i].workingHour, &fData[i].hourlyWage);
    
    fclose(data);
    
    //cal wage
    for(int i=0;i<g_count;i++) {
        if(fData[i].workingHour>40)
        {
            fData[i].totalPay+= (fData[i].workingHour-40) * (fData[i].hourlyWage * 1.5);
            fData[i].totalPay+= (fData[i].workingHour-(fData[i].workingHour-40)) * (fData[i].hourlyWage);
        }
        else fData[i].totalPay+=(fData[i].workingHour) * (fData[i].hourlyWage);
    }
    
    //ouput.txt
    output=fopen(argv[2], "w");
    
        fprintf(output, "ID\tNAME\tWORKING_HOUR\tHOURLY_WAGE\tWAGE(unit: manwon)\n");
        fprintf(output, "=========================================================\n");
        
        for(int i=0;i<g_count;i++)
            fprintf(output, "%s\t%s\t%d\t\t%d\t\t%.2f\n", fData[i].ID, fData[i].name, fData[i].workingHour, fData[i].hourlyWage, fData[i].totalPay);
    
        fprintf(output, "=========================================================\n");
    
    fclose(output);
    
}
 =====//
    srand(time(NULL));
    int option, play=1;
    char lineFeed;
    
    MEMBERS data[20]={  {"ASD001", "Rhee Syngman", rand()%59+10, (rand()%400+100)*100,  },
        {"ASD111", "Park Chunghee", rand()%59+10, (rand()%400+100)*100, },
        {"ASD203", "Chun Doohwan", rand()%59+10, (rand()%400+100)*100,  },
        {"BNM115", "Roh Taewoo", rand()%59+10, (rand()%400+100)*100,    },
        {"BNM234", "Kim Youngsam", rand()%59+10, (rand()%400+100)*100,  },
        {"BNM362", "Kim Daejung", rand()%59+10, (rand()%400+100)*100,   },
        {"CVB067", "Roh Moohyun", rand()%59+10, (rand()%400+100)*100,   },
        {"CVB168", "Lee Myungbak", rand()%59+10, (rand()%400+100)*100,  },
        {"DFG296", "Park Geunhye", rand()%59+10, (rand()%400+100)*100,  },
        {"DFG388", "Moon Jaein", rand()%59+10, (rand()%400+100)*100,    }, };
    
    for(int i=0;i<g_count;i++) {
        if(data[i].workingHour>40)
        {
            data[i].totalPay+= (data[i].workingHour-40) * (data[i].hourlyWage * 1.5);
            data[i].totalPay+= (data[i].workingHour-(data[i].workingHour-40)) * (data[i].hourlyWage);
        }
        else data[i].totalPay+=(data[i].workingHour) * (data[i].hourlyWage);
    }
    
    while(play)
    {
        option=menu();
        
        switch(option)
        {
            case'A':
                memTable(data);
                lineFeed=getchar();
                putchar('\n');
                break;
                
            case'B':
                memSearch(data);
                putchar('\n');
                break;
                
            case'C':
                ASCE(data);
                lineFeed=getchar();
                putchar('\n');
                break;
                
            case'D':
                total(data);
                lineFeed=getchar();
                putchar('\n');
                break;
                
            case'E':
                add(data);
                lineFeed=getchar();
                putchar('\n');
                break;
                
            case'Q':
                printf("Exit programme...\n");
                play=0;
                break;
                
            default:
                printf("Invalid option!\n");
                if(option!='\n') lineFeed=getchar();
                putchar('\n');
        }
    }
}

int menu(void)
{
    char menu;
    
    printf("**************************************************\n");
    printf("** A. The data of all members.                  **\n");
    printf("** B. Member search.                            **\n");
    printf("** C. Sorted data by name in ascending order.   **\n");
    printf("** D. Total working hour and wage.              **\n");
    printf("** E. Add a new member.                         **\n");
    printf("** Q. Quit the programme.                       **\n");
    printf("**************************************************\n");
    
    printf("Select menu<A~Q>:" );
    scanf("%c", &menu);
    
    return (menu>='a'&& menu<='z')? menu=toupper(menu) : menu;
}

void memTable(MEMBERS mem[])
{
    putchar('\n');
    printf("ID       NAME            WORKING_HOUR   HOURLY_WAGE    WAGE(manwon)\n");
    printf("===============================================================\n");
    
    for(int i=0;i<g_count;i++)
        printf("%-6s   %-13s   %3d             %6d        %6.2f\n", mem[i].ID, mem[i].name, mem[i].workingHour, mem[i].hourlyWage, mem[i].totalPay/10000);
    printf("===============================================================\n");
}

void memSearch(MEMBERS mem[])
{
    char inputName[15], lineFeed;
    int failed=1;
    
    putchar('\n');
    printf("Enter the name you are looking for: ");
    lineFeed=getchar();
    fgets(inputName, sizeof(inputName), stdin);
    inputName[strlen(inputName)-1]='\0';
    
    for(int i=0;i<g_count;i++) {
        if(!strcasecmp(mem[i].name, inputName))
        {
            putchar('\n');
            printf("Name         : %s              \n", mem[i].name);
            printf("Working hour : %d hours\n", mem[i].workingHour);
            printf("Hourly wage  : %d won   \n", mem[i].hourlyWage);
            printf("Wage         : %.2f manwon   \n", mem[i].totalPay/10000);
            failed=0;
            break;
        }
    }
    if(failed)
        printf("%s is not found!", inputName);
}

void ASCE(MEMBERS mem[])
{
    MEMBERS data_cpy[20];
    MEMBERS temp;
    
    for(int i=0;i<20;i++) //copy
        data_cpy[i]=mem[i];
    
    for(int i=0;i<g_count;i++)
        for(int j=0;j<g_count-1;j++)
            if(strcmp(data_cpy[j].name, data_cpy[j+1].name)>0)
            {
                temp=data_cpy[j];
                data_cpy[j]=data_cpy[j+1];
                data_cpy[j+1]=temp;
            }
    memTable(data_cpy);
}

void total(MEMBERS mem[])
{
    int totalWorkingHour=0;
    float totalWage=0;
    
    for(int i=0;i<g_count;i++) {
        totalWorkingHour+=mem[i].workingHour;
        totalWage+=mem[i].totalPay;
    }
    putchar('\n');
    printf("Total working hour : %7d hours\n", totalWorkingHour);
    printf("Total wage         : %7.2f manwon\n", totalWage/10000);
}

void add(MEMBERS mem[])
{
    char lineFeed;
    
    putchar('\n');
    
    if(g_count!=20)
    {
        do{
            do{
                printf("Enter the ID: ");
                scanf("%s", mem[g_count].ID);
                
            }while(checkDgt(mem));
            
            capID(mem);
            
        }while(checkDup(mem));
        
        printf("Enter the name: ");
        lineFeed=getchar();
        fgets(mem[g_count].name, sizeof(mem[g_count].name), stdin);
        capName(mem); //Captitalize the name
        mem[g_count].name[strlen(mem[g_count].name)-1]='\0'; //Remove '\n'
        
        printf("Enter the working hour: ");
        scanf("%d", &mem[g_count].workingHour);
        
        printf("Enter the hourly wage: ");
        lineFeed=getchar();
        scanf("%d", &mem[g_count].hourlyWage);
        
        if(mem[g_count].workingHour>40) //Calculate wage.
        {
            mem[g_count].totalPay+= (mem[g_count].workingHour-40) * (mem[g_count].hourlyWage * 1.5);
            mem[g_count].totalPay+= (mem[g_count].workingHour-(mem[g_count].workingHour-40)) * (mem[g_count].hourlyWage);
        }
        else mem[g_count].totalPay+=(mem[g_count].workingHour) * (mem[g_count].hourlyWage);
        
        g_count++;
    }
    else printf("Error!\n");
}

int checkDgt(MEMBERS mem[])
{
    if(strlen(mem[g_count].ID)!=6) {
        printf("The ID must be 6 characters!\n" );
        return 1;
    }
    else return 0;
}

void capID(MEMBERS mem[])
{
    for(int i=0;i<6;i++) //Capitalize the ID
        mem[g_count].ID[i]= (mem[g_count].ID[i]>='a' && mem[g_count].ID[i]<='z') ?toupper(mem[g_count].ID[i]) : mem[g_count].ID[i];
}

int checkDup(MEMBERS mem[])
{
    for(int i=0;i<g_count;i++)
        if(!strcmp(mem[i].ID, mem[g_count].ID))
        {
            printf("%s is already existed!\n", mem[g_count].ID);
            return 1;
        }
    return 0;
}

void capName(MEMBERS mem[g_count])
{
    mem[g_count].name[0]=toupper(mem[g_count].name[0]);
    
    for(int i=0;i<15;i++)
        if(mem[g_count].name[i]==' ') {
            mem[g_count].name[i+1]=toupper(mem[g_count].name[i+1]);
        }
}
