/*
JTSK-320112
6.1.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fptr; //file ptr
    char ch;
    char fname[50]; //file name
    int wordcount = 1;

    fgets(fname, sizeof(fname), stdin);
    fname[strlen(fname)-1] = '\0';


    fptr = fopen(fname,"r");

    if (fptr == NULL)
    {
        perror("Error opening file\n");
        return -1;
    }

    //reads character by character until eof
    while (ch != EOF)
    {
        char prev = ch;
        ch = getc(fptr);
        if (prev == ' ' || prev == ',' || prev == '?' || prev == '!' || prev == '\t' || prev == '\n' || prev == '\r')
        {

            if (ch != ' ' && ch!= ',' && ch!= '?' && ch != '!' && ch!= '.' && ch!= '\t' && ch!= '\n' && ch != '\r')
                wordcount++;
        }


    }

    printf("The file contains %d words.\n", wordcount);

    fclose(fptr);
    return 0;

}
