/*
https://www.acmicpc.net/problem/2884

*/

#include <stdio.h>


void getInput(int* h, int* m)
{
	scanf("%d %d", h, m);
}

int total_minute(int h, int m)
{
    return (h*60) + m;
}

int time_tuning(int minutes)
{
    if(minutes >= 0)
        return minutes;
    else    
        return minutes + (24*60);        
}

void splite_minute(int minutes, int *h, int *m)
{
    *h = minutes/60;
    *m = minutes%60;
}

int main(void)
{
    int h, m;
    int _h, _m;
    int total_min = 0;

    getInput(&h, &m);

    total_min = total_minute(h, m);
    
    total_min = total_min - 45;
    
    total_min = time_tuning(total_min);

    splite_minute(total_min, &_h, &_m);
    printf("%d %d\n", _h, _m);

    return 0;  
}