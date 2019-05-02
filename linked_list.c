/*
JTSK-320112
linked_list.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

struct list *push_front (struct list *my_list, int value)
{
    struct list *newel; //pointer to list
    newel = (struct list*)malloc(sizeof(struct list)); //allocating memory for new element

    if (newel == NULL )
    {
        printf(" Error allocating memory \n");
        return my_list ;
    } //for problems in allocating memory for newel

    newel->info = value;
    newel->next = my_list;

    return newel; //
}

struct list *push_back (struct list * my_list, int value )
{
    struct list *cursor, *newel ;
    cursor = my_list ; //helper pointer pointing to my_list
    newel = (struct list *) malloc ( sizeof ( struct list ));
    if ( newel == NULL )
    {
        printf (" Error allocating memory \n");
        return my_list ;
    }

    newel->info = value ;
    newel->next = NULL ;

    if (my_list == NULL )
        return newel ;
    //if empty array, then newel is at first position, and returns

    while (cursor -> next != NULL )
    {
        cursor = cursor -> next ;
    }
    //change the cursor pointer until it reaches the last element
    //at last, cursor points to null

    cursor -> next = newel ;
    //previous last element points to the new element
    //new element is now the last element

    return my_list ;
}

struct list *remove_el(struct list *my_list)
{
    struct list *cursor; //helping ptr
    cursor = my_list; //points to my_list

    if (cursor == NULL )
    {
        return my_list ;
    } //if list is empty, it returns empty list

    cursor = cursor -> next; //cursor points to 2nd element
    my_list = cursor;
    //my_list points to 2nd element now
    //it means, the 2nd element is now the 1st element of the new list


    return my_list;

};

void print_list (struct list *my_list)
{

    //prints until it reaches the null pointer
    while (my_list != NULL)
    {
        printf ("%d ", my_list -> info );
        my_list = my_list -> next ;
    }

    printf("\n");
}

//freeing list
void dispose_list (struct list *my_list)
{
    struct list *nextelem ;

    while (my_list != NULL )
    {
        nextelem = my_list->next ; //setting next element
        free (my_list); //freeing current element
        my_list = nextelem ; //updating my_list to point to next element
    }
}
