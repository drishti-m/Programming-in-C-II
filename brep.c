/*
JTSK-320112
brep.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    unsigned char c;
    scanf("%c", &c);

    printf("The decimal representation is: %d\n", c);

    unsigned char data = c; //additional: don't want c to change so.

    printf("The binary representation is: ");

    int x = sizeof(unsigned char) * 8; //bit size of data type

    while (i < x)
    {
        // if current bit is '1'
        if (((data)& 128) == 128) //bit mask = 10000000
            printf("1");
        else
            printf("0");

        // bitwise left shift
        // 'data' by 1
        data <<= 1;
        i++;
    }

    printf("\n");

    return 0;
}
