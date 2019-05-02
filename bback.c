/*
JTSK-320112
bback.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char c;
    scanf("%c", &c);

    printf("The decimal representation is: %d\n", c);

    unsigned char data = c;
    printf("The backwards binary representation is: ");
    unsigned int x = (int) c;
    printf("x %d\n",c);

    while (x > 0)
    {
        // if current bit is '1'
        if ((x & 1) == 1) //always have the bitmask converted in decimal here
            printf("1");
        else
            printf("0");

        // bitwise right shift
        // 'data' by 1
        x >>= 1;
    }
    printf("\n");



    return 0;

}
