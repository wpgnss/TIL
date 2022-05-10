/*
https://www.acmicpc.net/problem/2588

*/

#include <stdio.h>

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif


void getInput(int* input_a, int* input_b)
{
	scanf("%d %d", input_a, input_b);
}

int checkInput(int n)
{
    if( n >= 100 && n <= 999 )
        return TRUE;
    else
        return FALSE;

}

int getNextNum(int* num)
{
    int n = *num;
    
    if( n == 0 ) return 0;
    *num = n/10;
    return  n%10;
}

int main(void)
{
    int a, b, _b, next;
    int bInput;
    
    getInput(&a, &b);
    bInput = checkInput(a);
    if( bInput == FALSE )
    {
        printf("invalid input A\n");
        return 0;
    }

    bInput = checkInput(b);
    if( bInput == FALSE )
    {
        printf("invalid input B\n");
        return 0;
    }
    _b = b;

    do
    {
        next = getNextNum(&_b);
        printf("%d\n", a * next);
        
    } while ( _b != 0 );

    printf("%d\n", a * b);
        
    return 0;  
}
