/*
JTSK-320112
1.1.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

#define swap(x,y,m) {m t;t=x;x=y;y=t;}

int main()
{
    int a,b;
    double c,d;
    //declaration of variables

    scanf("%d", &a);
    scanf("%d", &b);
    //enter integers


    scanf("%lf", &c);
    scanf("%lf", &d);
    //enter float/double

    swap(a,b,int);
    swap(c,d,double);
    //swap occurs

    printf("After swapping:\n");
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%6lf\n",c);
    printf("%6lf\n",d);
    //printing

    return 0;

}
