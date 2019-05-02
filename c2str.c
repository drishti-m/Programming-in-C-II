/*
JTSK-320112
c2str.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char *fin; //array for dynamically allocated string
    char w1[100], w2[100]; //statically allocated strings

    scanf("%[^\n]s", (char*)&w1);
    //%[^\n]s takes input with space
    //conversion of (char*) required because &w1 = type *char[100]
    getchar(); //to ignore any space issues

    scanf("%[^\n]s", (char*) &w2);
    getchar();

    int size = strlen(w1) + strlen(w2);
    //size of the final string


    fin = (char*)malloc(size); //allocating memory for fin
    fin[0] = '\0'; //connecting fin to an empty word

    strcat(fin, w1); //fin= fin ++ w1
    strcat(fin,w2);//fin = fin ++ w2;

    printf("Result of concatenation: %s\n", fin);

    free(fin); //deallocating


    return 0;


}

