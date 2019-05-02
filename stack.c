/*
JTSK-320112
stack.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include "stack.h"
#include <stdio.h>
//#include <stdlib.h>

int isEmpty(stack *p)
{
    if ((p->count) == 0)
        return 0; //if empty
    else
        return -1; //not empty
}

void print_arr(stack *p)
{
    for(int i = (p->count) -1; i >=0 ; i--)
    {
        printf("%d ", p->array[i]);
    }
    printf("\n");
}
void push(stack *p, int x)
{
    if ((p->count)==12)
    {
        printf("Pushing Stack Overflow\n");
        return;

    }
    else
    {
        printf("Pushing %d\n", x);
        p->array[p->count] = x;
        p->count++;
        return;
    }

}

int pop(stack *p)
{
    if ((isEmpty(p)) == 0)
    {
        printf("Popping Stack Underflow\n");
        return 0;
    }
    else
    {
        p->count--;

        return p->array[p->count];
    }
}

void empty(stack *p)
{
    printf("Emptying Stack ");
    print_arr(p);
    for (int i = 0; i < p->count; i++)
    {
        pop(p);
    }
    p->count=0;

}


