/*
JTSK-320112
3.2.c
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
    newel->next = my_list; //gives address of my_list to the pointer newel.

    return newel; //
}

int count_size(struct list *my_list)
{
    int i = 0;
    while (my_list != NULL)
    {
        i++;
        my_list = my_list -> next ;
    }
    return i;

}; //gives size of list(i.e. number of elements in list)
//no direct way to get size of list


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

struct list *insert_el(struct list *my_list, int index, int x)
{

    int list_size = count_size(my_list);

    if ((index < 0) || (index > list_size))
    {
        printf("Invalid position!\n");
        return my_list;
    } //invalid

    else
    {
        struct list *cursor, *newel ;
        cursor = my_list ; //helper pointer pointing to my_list
        newel = (struct list *) malloc (sizeof(struct list));
        if (newel == NULL )
        {
            printf (" Error allocating memory \n");
            return my_list ;
        }


        newel->info = x;
        //storing value in new element


        if (my_list == NULL )
        {
            newel->next = NULL;
            return newel ;
        } //empty list

        else if (index == 0)
        {
            my_list = push_front(my_list,x);
            return my_list;
        } //if add at position 0, easy to use push_front function

        else
        {
            struct list *after_cursor; //another helper pointer

            for (int i = 0; i <(index -1); i++)
            {
                cursor = cursor -> next ;
            } //loop (index-1) times

            after_cursor = cursor -> next ; //after cursor points to element that is supposed to be next to inserted element
            cursor -> next = newel ; //the element supposed to be previous than inserted element
            //now points to the new element

            newel->next = after_cursor;
            //new element now points to next element as required

            return my_list ;
        }
    }
};

struct list *reverse(struct list* my_list)
{
    struct list *p, *c, *n;

    p = NULL; //ptr points to nyll
    c = my_list; //c points to 1st element
    n = c->next; //n points to 2nd element


    if (c == NULL )
    {
        return my_list ;
    }//returns empty list if list is empty


    while (c != NULL) //until current element is last element
    {
        c->next = p; // current element's next element points to p
        p = c; //p points to current element
        c = n; //c points to next element

        if (n != NULL)
            //if there is a next element left in the list,
            //change the ptr to the next
        {
            n = n->next;
        }

    }

    my_list = p;
    //p is the new list//update my_list
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

int main()
{
    struct list *my_list = NULL ;
    //list is empty at beginning

    char c = '\0';
    int x, index;

    while (c != 'q')
    {
        scanf("%c", &c);
        getchar();

        switch (c)
        {

        case 'i':

            scanf("%d", &index);
            getchar();
            scanf("%d", &x);
            getchar();

            my_list = insert_el(my_list, index,x);
            break;


        case 'R':
            my_list = reverse(my_list);
            break;

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

        default:
            break;


        }

    }

    dispose_list(my_list) ; //free the list

    return 0;
}




