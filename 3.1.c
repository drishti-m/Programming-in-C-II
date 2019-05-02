/*
JTSK-320112
3.1.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <stdlib.h>
#include <stdio.h>

struct list
{
    int info ;
    struct list *next ; /* self reference */
}; //defining list

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
    //printf("newel %x\n", newel);

    return newel; //returns address of list newel.
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
struct list *p;
p= my_list;
    //prints until it reaches the null pointer
    while (p != NULL)
    {
        printf ("%d ", p -> info );
        p = p -> next ;
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

int main()
{
    struct list *my_list; my_list = NULL ;
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
            //next of mylist points to new list 'new el'


            break;

        case 'a': //add at end of the list

            scanf("%d", &x);
            getchar();
            my_list = push_back(my_list, x) ;
            //my_list updated so that last element points to new el list. then, function my list is updated to main function

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




