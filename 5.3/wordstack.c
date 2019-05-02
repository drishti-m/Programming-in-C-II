/*
JTSK-320112
wordstack.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

int main()
{

    char sentence[200];
    char *wptr;
    stack p;

    while(1)
    {
        p.count = 0; //word count in a sentence initialized

        //printf("The program runs only for sentences less than 200 characters.\n");
        fgets(sentence, sizeof(sentence), stdin);
        sentence[strlen(sentence)-1] = '\0';

        if (strcmp(sentence, "exit") == 0)
            break;
        //end loop when "exit" is entered

        wptr = strtok(sentence," ");
        //strtok tokenizes/parses the given string using delimiter
        //char * strtok ( char * str, const char * delimiters );
        //eg, strtok(char*str, ";. ?");

        while (wptr!= NULL)
        {
            push(&p, wptr, p.count);
            wptr = strtok(NULL, " ");

        } //counts number of words and wptr holds one word each time in one loop

        if (p.count <= 1)
        {
            printf("Single word or no word entered.\nPalindrome check not performed.\n");
            printf("Please enter another word.\n");
        } //wordcount check

        else
        {
            //print_arr(&p);

            //storing stack of words in reverse order
            stack *q;
            q = reverse(&p);
            //print_arr(q);

            int check = 0;
            for (int i = 0; i < p.count; i++)
            {
                int z = strcmp(p.word[i], q->word[i]);
                if (z != 0)
                    check++;
                //if words in reverse order are not same, check will be !=0
            }

            if (check == 0)
                printf("The sentence is palindromic by words!\n");
            else
                printf("The sentence is not palindromic by words!\n");
        }
        //optional:
        //emptying stacks
        empty(&p);
        empty(&q);

    }
    return 0;
}
