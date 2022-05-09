/*
https://www.acmicpc.net/problem/1330

*/

#include <stdio.h>

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#define A_BIGGER_THAN_B ">"
#define B_BIGGER_THAN_A "<"
#define EQUAL_A_AND_B "=="

void getInput(int* input_a, int* input_b)
{
	scanf("%d %d", input_a, input_b);
}

int checkInput(int n)
{
    if( n >= -10000 && n <= 10000 )
        return TRUE;
    else
        return FALSE;

}

char* diff_two_integer(int a, int b)
{
    if( a == b )
        return EQUAL_A_AND_B;

    return ( a > b ) ? A_BIGGER_THAN_B : B_BIGGER_THAN_A;
}

int main(void)
{
    int a, b, n, i;
    int bInput;
    
    getInput(&a, &b);
    bInput = checkInput(a);
    if( bInput == FALSE )
    {
        printf("invalid input A\r\n");
        return 0;
    }

    bInput = checkInput(b);
    if( bInput == FALSE )
    {
        printf("invalid input B\r\n");
        return 0;
    }

    printf("%s\n", diff_two_integer(a, b));
    
    return 0;  
}