/*
 Course : C programming
 Section : 03
 Student ID: 21800779
 Name : Sion Han
 Discription: A simple calculator with four fundamental operators: addition, subtraction, multiplication, division.
 */

/*
#include <stdio.h>

int main(void)
{
    double num1, num2;
    char operator;

    printf("Enter the expression.(ex. 12.23+1.5): ");
    scanf("%lf%c%lf", &num1, &operator, &num2);
    
    if(operator=='+' || operator=='-' || operator=='/' || operator=='*')
    {
        switch(operator)
        {
            case '+':
                printf("Result:\n %.2lf%c%.2lf= %.2lf\n", num1, operator, num2, num1+num2);
                break;
                
            case '-':
                printf("Result:\n %.2lf%c%.2lf= %.2lf\n", num1, operator, num2, num1-num2);
                break;
                
            case '/':
                if(num2==0) printf("Numbers can't be divided by zero\n");
                else printf("Result:\n %.2lf%c%.2lf= %.2lf\n", num1, operator, num2, num1/num2);
                break;
                
            case '*':
                printf("Result:\n %.2lf%c%.2lf= %.2lf\n", num1, operator, num2, num1*num2);
                break;
        }
    }
    else printf("%c is an incorrect operator!!\n", operator);
    return 0;
}
*/
