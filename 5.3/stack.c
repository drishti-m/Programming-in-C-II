
/*
JTSK-320112
stack.h
Drishti Maharjan
d.maharjan@jacobs-university.de
*/
#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <string.h>

int isEmpty(stack *p)
{
    if ((p->count) == 0)
        return 0; //if empty
    else
        return -1; //not empty
}

void print_arr(stack *p)
{
    for(int i = 0; i <(p->count); i++)
    {
        printf("%s ", p->word[i]);
    }

    printf("\n");

}//print word by word

void push(stack *p, char* my_words, int x)
{
    if ((p->count)>= 20)
    {
        printf("Sorry, this program doesn't work for more than 20 words.\n");
        return;

    }//extra check
    else
    {
        int y = p->count;
        //printf("Pushing %s\n", my_words);
        strcpy(p->word[y], my_words);
        p->count++;
        return;
    }

}

//global stack

stack* reverse(stack *p)
{stack *q;
q = (struct stack*)malloc(sizeof(struct stack));
    q->count = 0;
    for(int i = (p->count) -1; i >=0 ; i--) //reverse loop
    {
        push(q, p->word[i], q->count);
        //storing in stack q
    }

    return q;

} //storing elements in stack in reverse order

char* pop(stack *p)
{
    if ((isEmpty(p)) == 0)
    {
        printf("Blank sentence\n");
        return 0;
    }
    else
    {
        p->count--;

        return p->word[p->count];
    }
}

void empty(stack *p)
{
    //printf("Emptying stack ");
    // print_arr(p);
    for (int i = 0; i < p->count; i++)
    {
        pop(p);
    }
    p->count=0;

}




