/*
JTSK-320112
stack.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>


void print_arr(stack *p)
{

    for(int i = (p->count) -1; i >=0 ; i--)
    {
        printf("%d", p->array[i]);
    }
    printf(".\n");
}

void push(stack *p, int x)
{

    if ((p->count)==32)
    {
        printf("Pushing Stack Overflow\n");
    }
    else
    {

        p->array[p->count] = x;
        p->count++;
    }

}





