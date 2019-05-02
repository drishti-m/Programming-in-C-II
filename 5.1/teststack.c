/*
JTSK-320112
teststack.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main()
{
    stack p;
    p.count = 0;
    int x;
    char c = '\0';

    while (c != 'q')
    {
        scanf("%c", &c);
        getchar();
        if (c == 's')
        {
            scanf("%d",&x);
            getchar();
            push(&p, x);
        }
        else if (c == 'p')
        {
            int y = pop(&p);
            if (y != 0)
            {
                printf("Popping %d\n", y);
            }
        }
        else if (c == 'e')
        {
            empty(&p);
        }
        else
        {
            //do nothing;
        }
    }

    printf("Quit\n");




    return 0;
}

