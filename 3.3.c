/*
JTSK-320112
3.3.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <stdlib.h>
#include <stdio.h>

//prototyping
struct list; //struct defn
void print_list(struct list *my_list); //print list
struct list* push_front(struct list* my_list, char c); //add element to beginning
void dispose_list(struct list *my_list); //free list
void reverse(struct list* my_list); //reverse list
struct list *remove_char(struct list* my_list, char a); //remove given character


struct list
{
    char data;
    struct list* prev;
    struct list* next;
};

struct list *head = NULL;
struct list *last = NULL;
struct list *current = NULL;
//global variables so that we can access anywhere

struct list* push_front(struct list* my_list, char c)
{
    struct list *newel = (struct list*)malloc(sizeof(struct list));
    newel->data = c;

    newel->prev = NULL;
    /*
        if (my_list == NULL)
        {
            newel->next = NULL;
            return newel;
        }else{
        newel->next =my_list;
        my_list->prev = newel;
        return newel;} //end it here*/


    head = my_list;


    if (head == NULL)
    {
        last = newel;
    }//if empty, make element last

    else
    {
        head->prev = newel;
    }//else update first element

    newel->next = head;
    //points to old first element;

    head = newel;
    my_list = head;
    //updating head and my_list

    return my_list;

};//note: head might not be imp for this function, but is used as helper in other functions
//so, updating head here too, even though here head and new_el does the same thing


//freeing list
void dispose_list(struct list *my_list)
{
    struct list *nextelem ;

    while (my_list != NULL )
    {
        nextelem = my_list->next ; //setting next element
        free (my_list); //freeing current element
        my_list = nextelem ; //updating my_list to point to next element
    }
};


void reverse(struct list* my_list)
{
    struct list *p = my_list; //ptr to 1st element
    p->prev = NULL; //1st element previous ptr = NULL
    struct list *l = NULL; //ptr to last element

    if (my_list == NULL)
    {
        // printf("empty list\n");
        //do nth as per question
    }//empty list

    else
    {
        while (p!= NULL) //while ptr doesn't reach last element
        {
            l = p;
            p = p->next;
        } //after this, l points to last element


        //start printing from last element
        //until element's prev points to null
        while (l!= NULL)
        {
            printf("%c ", l->data);
            l = l->prev;
        }
        printf("\n");
    }
};

struct list *remove_char(struct list* my_list, char a)
{

    //start from first link again
     struct list *c = head;
     struct list *h = c;
     //helper pointer to store references
     //when c changes in loop

     if (head == NULL)
     {
         return my_list;
     }//if empty list, return empty

     int found = 0;
     //var used to see if character exists in list

     //go through the list until we find the character & don't reach the end
     while (c!= NULL)
     {

         if (c->data != a)
         {
             c = c-> next;
             h = c;//storing reference to current link
         }//change pointer until we find the element

         else
         {
             h = c; //storing reference to current link
             found++;

             //if character is 1st element:
             if (c == head)
             {

                 c->next->prev = NULL;
                 c = c->next;
                 head = c;

             }//first element of list is now the previous second element
             //head has to change as well

             //if char = last element
             else if (c == last)
             {
                 last = c-> prev;
                 c->prev->next = NULL;

             }//last element points to previous 2nd last element
             //head remains same

             else //if char is in middle
             {
                 c->prev->next = c->next;
                 c->next->prev = c->prev;

             }//update the pointers of element before and after the removing character(in old list)
             //head remains same

             c = h->next;
             //changing c ptr to see if there is the same char again in the list
         }
     } //loop ends when reaches end of list

     c = head;
     //as the actual proper list is always referred through head,(because we change c very often)
     //we pass c = head at last.


     //if character is not in the list
     if (found == 0)
     {
         printf("The element is not in the list!\n");
         return my_list;
     }
     else //if character was found in list
     {
         my_list = c; //updating my_list;
         return my_list;
     }

};


void print_list (struct list *my_list)
{

    //prints until it reaches the null pointer
    while (my_list != NULL)
    {
        printf ("%c ", my_list -> data );
        my_list = my_list -> next ;
    }

    printf("\n");
}



int main()
{
    struct list* my_list = NULL;

    char c;
    int x;

    while (1)
    {
        scanf("%d", &x);
        getchar();

        switch(x)
        {
        case 1:
            scanf("%c", &c);
            getchar();
            my_list = push_front(my_list, c);
            break;

        case 2:
            scanf("%c", &c);
            getchar();
            my_list = remove_char(my_list,c);
            break;

        case 3:

            print_list(my_list);
            break;

        case 4:
            reverse(my_list);
            break;

        case 5:
            dispose_list(my_list);
            exit(0);
            break;

        default:
            break;

        }

    }

    return 0;
}

