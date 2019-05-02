/*
JTSK-320112
ccomp.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

#define More_Output
//macro for intermediate results

int main()
{
    int n,i, total = 0;
    scanf("%d", &n); //input for dimension

    int x[n],y[n], intm[n]; //x comp, y comp, and intermediate product array

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    } //takes input of x components

     for (i = 0; i < n; i++)
    {
        scanf("%d", &y[i]);
    }//takes input of y components

    #ifdef More_Output
        printf("The intermediate product values are:\n");

        #endif // def

    for (i = 0; i < n; i++)
    {
        intm[i] = x[i] * y[i]; //intermediate product
        total = total + intm[i]; //total sum

        #ifdef More_Output

        printf("%d\n", intm[i]); //print intermediate values
        #endif // def

    }

    printf("The scalar product is: %d\n", total); //final scalar product

    return 0;
}
