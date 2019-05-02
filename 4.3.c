/*
JTSK-320112
4.3.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/


#include <stdio.h>
#include <stdlib.h>

//comparator function for qsort in ascending order
int asc_func (const void * a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

//comparator function for qsort in descending order
int desc_func (const void *a, const void *b)
{
    return (*(int*)b - *(int*)a);
}

//function to print in ascending order
void asc(int* array, int n)
{
    qsort(array, n, sizeof(int), asc_func);
    for(int i = 0 ; i < n; i++ )
    {
        printf("%d ", array[i]);
    }
    printf("\n");

}

//function to print in descending order
void desc(int* array, int n)
{
    qsort(array,n, sizeof(int), desc_func);
    for(int i = 0 ; i < n; i++ )
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

//function to quit
void quit(int* array, int n)
{
    exit(0);
}

typedef void (*ptr)(int*, int);
//pointer to function that takes 2 arg

int main()
{
    int n;char c;
    scanf("%d",&n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    ptr f_array[] = {asc,desc,quit};
    //array of f_pointers

    while(1)
    {

        getchar();
        scanf("%c", &c);

        if (c == 'a')
            f_array[0](arr,n);
        else if(c == 'd')
            f_array[1](arr,n);
        else if (c == 'e')
            f_array[2](arr,n);
        /* else
            printf("Invalid char\n"); //optional */

    }

    return 0;

}
