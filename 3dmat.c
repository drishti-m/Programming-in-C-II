
/*
JTSK-320112
3dmat.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r, c, d, i,j,k;

    scanf("%d", &r); //dimension1
    scanf("%d", &c);//dimension2
    scanf("%d", &d);//dimension3


    int ***mat;

    mat = (int***) malloc(sizeof(int**)*r);
    //allocating memory for dimension1
    for (i = 0; i < r; i++)
    {
        mat[i] = (int **)malloc(sizeof(int*)*c); //dimension2
        for (j = 0; j < r; j++)
        {
            mat[i][j] = (int*)malloc(sizeof(int)*d);//dimension3
        }
    }


    //taking input from user for matrix
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            for (k = 0; k < d; k++)
            {
                scanf("%d", &mat[i][j][k]);
            }

        }
    }


    //printing sections parallel to XOY
    for (k = 0; k < d; k++)
    {
        printf("Section %d:\n", k+1);
        //logic here: one section has all elements with same dimension 3 index

        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                printf("%d ", mat[i][j][k]);
            }
            printf("\n");
        }
    }


//deallocate a 3D array
    for(i = 0; i < c; i++)
    {
        for(int j = 0; j < d; j++)
        {
            free(mat[i][j]);
        }
        free(mat[i]);
    }
    free(mat);


    return 0;
}

