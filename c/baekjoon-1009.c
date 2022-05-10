/*
https://www.acmicpc.net/problem/1009

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void getCount(int* count)
{
	scanf("%d", count);
}

void getInput(int* base, int* power)
{
	scanf("%d %d", base, power);
}

int getRepeatedNumber(int n)
{
    int repeatNumber[10] = 
    {
        0, 1, 4, 4, 2, 1, 1, 4, 4, 2
    };

    return repeatNumber[n];
}

typedef struct POW_TABLE
{
    int base;
    int pow;
    int rest_of_ten;

} POW_TABLE;
// 1과 0은 반복되지 않아서 알고리즘 실패..
int main(void)
{
    int count=0;
    int lastnumber_of_base, i;
    int rest_number_devided_by_reapeated_number;
    POW_TABLE *table_power_of_base; 

    for(i=0; i<20; i++)
    {
        printf("TEST %d\n", pow(61, i));
    }
    return 0;
    getCount(&count);
    table_power_of_base = (POW_TABLE *) malloc(count * sizeof(POW_TABLE));

    for(i=0; i<count; i++)
    {
        getInput( &(table_power_of_base+i)->base, &(table_power_of_base+i)->pow );
    }
    
    for(i=0; i<count; i++)
    {
        lastnumber_of_base = ((table_power_of_base+i)->base) % 10;
        // printf("lob %d\n", lastnumber_of_base);
        rest_number_devided_by_reapeated_number = ((table_power_of_base+i)->pow) % getRepeatedNumber(lastnumber_of_base);
        (table_power_of_base+i)->rest_of_ten = ((int)pow(lastnumber_of_base, rest_number_devided_by_reapeated_number) % 10 );
    }

    for(i=0; i<count; i++)
    {
        // printf("i=%d, val=%d %d %d\n", i, (table_power_of_base+i)->base, (table_power_of_base+i)->pow, (table_power_of_base+i)->rest_of_ten);
        printf("%d\n", (table_power_of_base+i)->rest_of_ten);
    }

    

    free(table_power_of_base);
    return 0;
}
