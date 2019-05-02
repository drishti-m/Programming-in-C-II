/*
JTSK-320112
parith.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/


#include <stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n); //no of elements in array

    float *arr1, *arr2; //allocating pointers to get the count
    float array[n]; //array of elements
    arr1 = &array[0]; //pointer arr1 points to first element in array[n]

    arr2 = &array[0]; //pointer arr2 points to first element in the array[n]

    for (i = 0; i < n; i++)
    {
        scanf("%f", &array[i]);
    } //storing elements in array

    while (arr1 != NULL) //until last element is reached
    {
        if (*arr1 > 0) //dereferencing arr1, and checking if element is +ve
        {
            arr1++; //if element is +ve, the address is incremented by 1 and points to next element
        }
        else

            break; //if -ve, it comes out of the loop
    }
    int finals = arr1 - arr2; //address of negative element - address of 1st element


    printf("Before the first negative value: %d elements\n",finals);


    return 0;
}
