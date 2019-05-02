/*
JTSK-320112
queue.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

/**
 * @file queue.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

static void copy_to_node(Item item, Node *pn);
//static void copy_to_item(Node *pn, Item *pi);

void initialize_queue(Queue *pq)
{
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

int queue_is_full(const Queue *pq)
{
    return pq->items == MAXQUEUE;
}

int queue_is_empty(const Queue *pq)
{
    return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
    return pq->items;
}

int enqueue(Item item, Queue *pq)
{
    if (queue_is_full(pq))// full or null ptr
    {
        return -1;
    }
    else
    {
        Node *newnode = (Node*)malloc(sizeof(Node));
        if (newnode == NULL)
            return -1; //allocation error

        newnode->next = NULL; //last element always points at null

        copy_to_node(item, newnode); //updates nodes

        if (pq->rear != NULL) //if there are elements in the queue
            {pq->rear->next = newnode;} //build connection/link
        pq->rear = newnode; //update queue ptr

        if (pq->front == NULL) //if list is empty
            {pq->front = newnode;} //first element is now the new element

        pq->items++;//increase number of elements in queue line




        return 0;
    }

}

int dequeue(Item *pitem, Queue *pq)
{
return 0;
}

void empty_queue(Queue *pq)
{
    Item dummy;
    while (!queue_is_empty(pq))
    {
        dequeue(&dummy, pq);
    }
    return;
}

static void copy_to_node(Item item, Node *pn)
{
    pn->item = item;
}

/*static void copy_to_item(Node *pn, Item *pi)
{
    *pi = pn->item;
} */
