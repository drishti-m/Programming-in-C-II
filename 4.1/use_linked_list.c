/*
JTSK-320112
linked_list.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>


int main()
{
    struct list *my_list = NULL ;
    //list is empty at beginning

    char c = '\0';
    int x;

    while (c != 'q')
    {
        scanf("%c", &c);
        getchar();

        switch (c)
        {

        case 'b': //add at the beginning of list

            scanf("%d", &x);
            getchar();
            my_list = push_front(my_list, x) ;

            break;

        case 'a': //add at end of the list

            scanf("%d", &x);
            getchar();
            my_list = push_back(my_list, x) ;

            break;

        case 'p': //print the list

            print_list(my_list) ;
            break;


        case 'r': //remove the first element from the list

            my_list = remove_el(my_list);
            break;

        }

    }

    dispose_list(my_list) ; //free the list

    return 0;
}

