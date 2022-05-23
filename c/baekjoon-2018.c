/*
https://www.acmicpc.net/problem/2018

*/

#include <stdio.h>

void getInput(int* num)
{
	scanf("%d", num);
}

int main(void)
{
    int input_num;
    int sum_of_sequencial_number = 0;
    int left_ptr = 0, right_ptr = 0;
    int number_of_sequencial_number = 0;

    getInput(&input_num);
    // printf("input num == %d\n", input_num);
    while( 1 )
    {
        while( sum_of_sequencial_number != input_num )
        {
            while( sum_of_sequencial_number > input_num )
            {    
                sum_of_sequencial_number -= ++left_ptr;
                // printf(" left working.. : %d, %d\n", sum_of_sequencial_number, left_ptr);
            }
            while( sum_of_sequencial_number < input_num )
            {
                sum_of_sequencial_number += ++right_ptr;
                // printf(" right working.. : %d, %d\n", sum_of_sequencial_number, right_ptr);
            }
        }
        // printf(" ====== %d, (left %d, right %d)\n", right_ptr - left_ptr - 1, left_ptr+1, right_ptr);
        // printf("%d\n", right_ptr - left_ptr - 1);
        number_of_sequencial_number++;

        if( right_ptr == input_num ) break;
        sum_of_sequencial_number += ++right_ptr;
    }
    printf("%d\n", number_of_sequencial_number);


    return 0;
}
