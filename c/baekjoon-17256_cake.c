/*
https://www.acmicpc.net/problem/17256

*/

#include <stdio.h>

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif


typedef struct cake
{
    int x;
    int y;
    int z;
} CAKE;


void getInput(CAKE* _cake)
{
	scanf("%d %d %d", &_cake->x, &_cake->y, &_cake->z);
}

int checkInput(CAKE _cake)
{
    // printf("value: %d, %d, %d\n", _cake.x, _cake.y, _cake.z);
    
    if( _cake.x < 1 || _cake.x > 100 )
        return FALSE;
    else if( _cake.y < 1 || _cake.y > 100 )
        return FALSE;
    else if( _cake.z < 1 || _cake.z > 100 )
        return FALSE;
    else
        return TRUE;
}

void calc_cake(CAKE* _b_cake, CAKE _a_cake, CAKE _c_cake)
{
    // a 🍰 b = c
    // a 🍰 b = (a.z + b.x, a.y × b.y, a.x + b.z)
    // b = (c.x - a.z, c.y / a.y, c.z - a.x)
    
    _b_cake->x = _c_cake.x - _a_cake.z;
    _b_cake->y = _c_cake.y / _a_cake.y;
    _b_cake->z = _c_cake.z - _a_cake.x;

}

int main(void)
{
    int bInput;
    CAKE aCake, bCake, cCake;

    getInput(&aCake);
    getInput(&cCake);
    bInput = checkInput(aCake);
    if( bInput == FALSE )
    {
        printf("invalid input a\r\n");
        return 0;
    }

    bInput = checkInput(cCake);
    if( bInput == FALSE )
    {
        printf("invalid input c\r\n");
        return 0;
    }

    // printf("%d %d %d\r\n", aCake.x, aCake.y, aCake.z);
    
    calc_cake(&bCake, aCake, cCake);


    printf("%d %d %d\n", bCake.x, bCake.y, bCake.z);
    
    return 0;  
}