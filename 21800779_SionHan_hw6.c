/*

 Course : C programming
 Section : 03
 Student ID : 21800779
 Name : Sion Han
 Discription : A scrabble game which calculates score depending on each letter.
 
 */
/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char word;
    int score;
    
    
    while(1)
    {
        score=0;
        
        printf("Enter any words: ");
        scanf("%c", &word);
        
        if(word=='\n')
        {
            printf("Exit program...");
            break;
        }
            while(1)
            {
                if(word>= 97 && word<= 122) word= toupper(word);
            
                if(word>= 65 && word<= 90)
                {
                    if(word=='D' || word=='G') score+=2;
        
                    else if(word=='B' || word=='C' || word=='M' || word=='P') score+=3;
        
                    else if(word=='F' || word=='H' || word=='V' || word=='W' || word=='Y') score+=4;
        
                    else if(word=='K') score+=5;
        
                    else if(word=='J' || word=='X') score+=8;
        
                    else if(word=='Q' || word=='Z') score+=10;
        
                    else if(word=='A' || word=='E' || word=='I' || word=='L' || word=='N' || word=='O' || word=='R' || word=='S' || word=='T' || word=='U') score+=1;
                }
                word=getchar();
                
                if(word=='\n')
                {
                    printf("The score is %d\n", score);
                    break;
                }
            }
    }
}
 */
