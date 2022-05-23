/*
https://www.acmicpc.net/problem/4673

*/

#include <stdio.h>

#define IS_SELF_NUMBER 0
#define IS_NOT_SELF_NUMBER 1

#define MAX_SELF_NUMBER 10000

void find_self_number(int *num_array, int number)
{
    int num_iter = number;
    int temp_num = number;
    
    while(temp_num <= MAX_SELF_NUMBER)
    {
        num_iter = temp_num;

        do
        {
            temp_num += num_iter % 10;
            num_iter = num_iter / 10;
        } while ((num_iter/10) != 0);

        temp_num += num_iter;
        
        if(temp_num <= MAX_SELF_NUMBER)
        {
            if(*(num_array+temp_num) == IS_NOT_SELF_NUMBER )
            {
                break;
            }
            else
            {
                *(num_array+temp_num) = IS_NOT_SELF_NUMBER;
            }
        }
    }
}



int main(void)
{
    int count=0;
    int self_number_array[MAX_SELF_NUMBER + 1] = {IS_SELF_NUMBER,};
    int i, j;

    for(i=1; i<=MAX_SELF_NUMBER; i++)
    {
       if(self_number_array[i] != IS_NOT_SELF_NUMBER)
       {
            find_self_number(self_number_array, i);
       }
    }


    for(i=1; i<=MAX_SELF_NUMBER; i++)
    {
        if(self_number_array[i] == IS_SELF_NUMBER)
            printf("%d\n", i);
    }

    return 0;
}
