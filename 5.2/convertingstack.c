/*
JTSK-320112
teststack.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"

/**
 * @brief bin converts decimal to binary
 *
 * @param stack *p The pointer to stack structure
 * @param x -decimal no
 *
 * @return Returns void
 */
void bin(stack *p, int x)
{
    while (x !=0)
    {
        int rem = x % 2;
        push(p, rem);
        x  = (x - rem)/2;
    }
}

int main()
{
    stack p;
    p.count = 0;
    int x;
    scanf("%d", &x);
    bin(&p, x);
    printf("The binary representation of %d is ",x);
    print_arr(&p);

    return 0;
}
