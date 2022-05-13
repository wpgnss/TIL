/*
https://www.acmicpc.net/problem/3460

*/

#include <stdio.h>

void getCount(int* count)
{
	scanf("%d", count);
}

void getInput(int* num)
{
	scanf("%d", num);
}

int main(void)
{
    int count=0;
    int input_array[10] = {0,};
    int bit_mask=0x01;
    int i, j;

    getCount(&count);
    
    for(i=0; i<count; i++)
    {
        getInput( &input_array[i] );
    }


    for(i=0; i<count; i++)
    {
        bit_mask = 0x01;

        for(j=0; j<21; j++)
        {
            if(bit_mask > input_array[i])
            {
                printf("\n");
                break;
            }
            if(input_array[i] & bit_mask)
            {
                printf("%d ", j);
            }
            bit_mask = bit_mask<<1;
        }
    }

    return 0;
}
