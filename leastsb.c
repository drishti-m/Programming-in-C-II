/*
JTSK-320112
leastsb.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <stdlib.h>
#include <stdio.h>
#define change(x) {x=x & 00000001;}
//macro definition to replace with expression
int main()
{

    unsigned char x;
    scanf("%c", &x);
    //takes input

    printf("The decimal representation is: %d\n", x);
    //prints decimal representation
    change(x);
    //replaces with macro
    printf("The least significant bit is: %d\n", x);
    //prints the least significant bit
    return 0;

}
