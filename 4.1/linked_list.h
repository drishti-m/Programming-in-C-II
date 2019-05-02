/*
JTSK-320112
linked_list.h
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

struct list
{
    int info ;
    struct list *next ; /* self reference */
}; //defining list


struct list *push_front (struct list *my_list, int value);
struct list *push_back (struct list *my_list, int value);
struct list *remove_el(struct list *my_list);
void print_list (struct list *my_list);
void dispose_list (struct list *my_list);
