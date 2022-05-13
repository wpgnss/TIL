/*
https://www.acmicpc.net/problem/1085

*/

#include <stdio.h>

#define min(x, y) (x) < (y) ? (x) : (y)

void getInput(int* x, int* y, int* w, int* h)
{
	scanf("%d %d %d %d", x, y, w, h);
}

int main(void)
{
    int x, y, w, h;
    int min_distance = 1000;
    
    getInput(&x, &y, &w, &h);

    min_distance = min( min(x, w-x), min(y, h-y) );

    printf("%d\n", min_distance);
    return 0;  
}