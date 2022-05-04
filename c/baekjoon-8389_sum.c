/*
https://www.acmicpc.net/problem/8393

*/

#include <stdio.h>

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

int getInput(void)
{
    int n;
	scanf("%d", &n);
    return n;
}

int checkInput(int n)
{
    if( n >= 1 && n <= 10000 )
        return TRUE;
    else
        return FALSE;

}

void calc_sum(int* total, int n)
{
    *total = (*total) + n;
    // return (*total) + n ;
}

int main(void)
{
    int n, i;
    int bInput;
    int total = 0;
    
    n = getInput();
    bInput = checkInput(n);
    if( bInput == FALSE )
    {
        printf("invalid input\r\n");
        return 0;
    }
    // printf("n == %d\r\n", n);
    for ( i = 1; i <= n; i++ )
    {
        calc_sum(&total, i);
    }
    printf("%d\n", total);
    
    return 0;  
}