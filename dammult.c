/*
JTSK-320112
dammult.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, p, k, i,j, sum = 0;
    scanf("%d", &n);//number of rows in Matrix A
    scanf("%d", &m);//no of cols in Matrix A = no of rows in Matrix B
    scanf("%d", &p);//no of cols in Matrix B

    int **matr1, **matr2, **matr3; //pointers for dyn alloc of matrixes

    matr1 = (int**) malloc(sizeof(int*)*n);
    matr2 = (int**) malloc(sizeof(int*)*m);
    matr3 = (int**) malloc(sizeof(int*)*n);
    //allocating memory for rows
    //check null pointers


    for (i = 0; i < n; i++)
    {
        matr1[i] = (int*)malloc(sizeof(int)*m);
    }
    for (i = 0; i < m; i++)
    {
        matr2[i] = (int*)malloc(sizeof(int)*p);

    }

    for (i = 0; i < p; i++)
    {
        matr3[i] = (int*)malloc(sizeof(int)*n);

    }
    //allocating memory for each element (via columns)


    //taking input from user for matrices
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &matr1[i][j]);
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p; j++)
        {
            scanf("%d", &matr2[i][j]);
        }
    }

    //multiplication of Matrix A and Matrix B
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < p; j++)
        {
            for (k = 0; k < m; k++)
            {
                sum = sum + matr1[i][k]* matr2[k][j];
            }

            matr3[i][j] = sum;
            sum = 0;
        }
    }//storing elements in matr3


    printf("Matrix A:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", matr1[i][j]);
        }
        printf("\n");
    } //print Matrix A

    printf("Matrix B:\n");


    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p; j++)
        {
            printf("%d ", matr2[i][j]);
        }
        printf("\n");
    }//print Matrix B

    printf("The multiplication result AxB:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < p; j++)
        {
            printf("%d ", matr3[i][j]) ;
        }
        printf("\n");
    }//print matrix after multiplication

    //deallocation:
    for (i = 0; i < m; i++) //m=no of cols in matr1
    {
        free(matr1[i]);
    }
    free(matr1);
    //matr1

    for (i = 0; i < p; i++) //p = no of cols in matr2 and matr3
    {
        free(matr2[i]);
        free(matr3[i]);

    }
    free (matr3);
    free(matr2);
//deallocating matr2 and matr3
    return 0;
}
