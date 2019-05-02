/*
JTSK-320112
4.4.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct person
{
    char name[30];
    int age;
};

typedef struct person person;
//making this struct global
//by doing this, we can access struct anywhere
//also, while passing parameters, we can pass person *.., instead of struct person *..


void bubblesort(void* arr_ptr, size_t n, size_t size, int(*comp)(const void *, const void*))
{

    if (n <= 1)
        return;
    //one element array- no sort required

    void *temp_p = malloc(size); //temp ptr for swapping

    if (temp_p == NULL)
    {
        printf("error allocating memory\n");

    }

    void *ptr1, *ptr2 ; //ptrs to use for comparing consecutive elements
    //tried dynamiclly allocating these ptrs, but it's invalid in this context
    //doesn't work

    int swaps = 1;

    while(swaps) //loop runs until swap = 0 (i.e. when no more swap required)
    {
        swaps = 0;

        for (int i = 1; i < n; i++)
        {

            ptr1 = arr_ptr + (i - 1) * size; //when i = 1, ptr1 points to 0th index, next time 1st and so on.
            ptr2 = arr_ptr + i * size;//ptr2 points to element after ptr1's element


            //if element in ptr1 is greater than element in ptr2
            if ((comp(ptr1,ptr2)) > 0)
            {
                //swapping:

                memcpy(temp_p, ptr1, size);
                memcpy(ptr1, ptr2, size);
                memcpy(ptr2, temp_p, size);
                //then new ptr1 points to old ptr2
                //and new ptr2 points to old ptr1

                //memcpy makes things easier,but try TA's method too : note to self
                swaps = 1;
            }

        }
    }

    free(temp_p);
    //freeing dynamically allocated memory

    return;
}

//function to compare names
int cmpname(const void *ptr1, const void *ptr2)
{
    person *P1 = (person*) ptr1; //P1 points to content of ptr1 in the list person
    person *P2 = (person*) ptr2;
    //looks a bit weird, need to revise: note to self

    int cmp_res = strcmp(P1->name, P2->name);
    //returns >0 if P1 is greater and 0 if equal

    if (cmp_res != 0)
        return cmp_res;
    else //if same name, compare ages
    {
        if ((P1->age) > (P2->age))
            return 1;
        else
            return -1;
    }

}

int cmpage(const void *ptr1, const void *ptr2)
{
    person *P1 = (person*) ptr1; //P1 points to content of ptr1 from list person
    person *P2 = (person*) ptr2;

    int ret;

    if ((P1->age) > (P2-> age))
    {
        ret = 1;
    }
    else if ((P1->age) < (P2->age))
    {
        ret = -1;
    }
    else
        ret = cmpname(ptr1,ptr2);

    return ret;
} //returns 1 if P1 age is higher, and compares names if both are same age


//printing data
void print_data(person* arr_ptr, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("{%s, %d}; ", arr_ptr[i].name, arr_ptr[i].age);
        //accessing data element wise
    }
    printf("\n");
    return;
}

int main()
{
    int n,i;
    char str[100];
    scanf("%d", &n);
    getchar();

    struct person* array = (person*) malloc(sizeof(person) * n);

    if (array == NULL)
    {
        printf("error allocating memory\n");
    }

    for (i = 0; i < n; i++)
    {
        fgets(str, sizeof(str), stdin);
        sscanf(str, "%s", array[i].name);

        scanf("%d", &(array[i].age));
        getchar();

    }


    bubblesort(array, n, sizeof(person), cmpname);
    print_data(array, n);

    bubblesort(array, n, sizeof(person), cmpage);
    print_data(array,n);

    free(array);

    return 0;
}
