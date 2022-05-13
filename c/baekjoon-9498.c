/*
https://www.acmicpc.net/problem/9498

*/

#include <stdio.h>

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#define GRADE_A 90
#define GRADE_CHAR_A 'A'
#define GRADE_B 80
#define GRADE_CHAR_B 'B'
#define GRADE_C 70
#define GRADE_CHAR_C 'C'
#define GRADE_D 60
#define GRADE_CHAR_D 'D'
#define GRADE_CHAR_F 'F'

void getInput(int* score)
{
	scanf("%d", score);
}

int checkInput(int n)
{
    if( n >= 0 && n <= 100 )
        return TRUE;
    else
        return FALSE;
}

int main(void)
{
    int score;
    char grade = GRADE_CHAR_F;
    int bInput;
    
    getInput(&score);
    bInput = checkInput(score);
    if( bInput == FALSE )
    {
        printf("invalid input Score\r\n");
        return 0;
    }

    if(score >= GRADE_A)
        grade = GRADE_CHAR_A;
    else if(score >= GRADE_B)
        grade = GRADE_CHAR_B;
    else if(score >= GRADE_C)
        grade = GRADE_CHAR_C;
    else if(score >= GRADE_D)
        grade = GRADE_CHAR_D;

    printf("%c\n", grade);
    return 0;  
}