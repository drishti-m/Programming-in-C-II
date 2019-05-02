/*
JTSK-320112
midrv.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

#define twomin(x,y) ((x) < (y)  ? (x) : (y))
//macro for minimum of two values
#define min(x,y,z) twomin((twomin(x,y)),z)
//min of 3 numbers
#define twomax(x,y) ((x) > (y)  ? (x) : (y))
//macro for max of two values
#define max(x,y,z) twomax((twomax(x,y)),z)
//max for 3 numbers
#define mid_range(x,y,z) {m = ((min(x,y,z)) + (max(x,y,z)))/2};
//macro for mid range

int main()
{
    float a,b,c;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    //input 3 numbers

    float m = mid_range(a,b,c);
    //m from definition of mid_range
    printf("The mid-range is: %6f\n", m);
    //print result


    return 0;

}
