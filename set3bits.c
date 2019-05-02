/*
JTSK-320112
set3bits.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char c;
    int b1,b2,b3,i = 0;
    int x = sizeof(unsigned char) * 8; //bit size of data type

    //input required
    scanf("%c", &c);
    scanf("%d", &b1);
    scanf("%d", &b2);
    scanf("%d", &b3);

    unsigned char data = c;
    //assigning c to variable data
    printf("The decimal representation is: %d\n", c);

    printf("The binary representation is: ");
    while (i < x)
    {

        // if current bit is '1'
        if (((data)& 128) == 128) //bit mask = 10000000
            printf("1");
        else //if current bit is '0'
            printf("0");

        // bitwise left shift
        // 'data' by 1
        data <<= 1;
        i++; //i loop to help control the no of bits to be printed
    }
    printf("\n");


    //resetting values:
    data = c;
    i = 0;

    //changing required bits to 1
    printf("After setting the bits: ");
    while (i < x)
    {

        // if current bit is '1'
        if ((((data) & 128) == 128) ||   //bit mask = 10000000
                (i == (x - b1 - 1)) || (i == (x -b2 - 1)) || (i == (x - b3 - 1)))
            //if i = bit positions to set 1(here, most sig bit position = 0th position)
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

