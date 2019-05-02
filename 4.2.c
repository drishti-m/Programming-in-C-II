/*
JTSK-320112
4.2.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void upper(char *mystring)
{
    while(*mystring != '\0'){
        printf("%c", toupper(*mystring));
        mystring++;
        //mystring++ works because char size is 1, and 2nd character &1st character's memory location differs by 1
    }

}//change all characters to upper case

void lower(char *mystring)
{
    while (*mystring != '\0')
    {
        printf("%c", tolower(*mystring));
        mystring++;
    }
}//change all chars to low case

void switchc(char *mystring)
{
    while (*mystring != '\0')
    {
        if(tolower(*mystring) == *mystring)
        {
            printf("%c", toupper(*mystring));
        }
        else
        {
            printf("%c", tolower(*mystring));
        }
        mystring++;
    }
}//switch characters

void quit(char *mystring)
{
    exit(0);
}

typedef void (*ptr)(char*);
//return type= void
//parameter = pointer to function that takes char* as its parameter

int main()
{
    char *mystring, c, ch = '0' ;
    int i =0, j = 1;

    //dynamically allocating and reallocating memory for string as per input:
    mystring = (char*)malloc(sizeof(char));
     while (c != '\n') {
    // read the input from keyboard standard input
    c = getc(stdin);

    // re-allocate (resize) memory for character read to be stored
    mystring = (char*)realloc(mystring, j * sizeof(char));

    // store read character by making pointer point to c
    mystring[i] = c;
    i++;
    j++;
  }
  mystring[i] = '\0';

//f_array is an array that stores addresses of functions required
  ptr f_array[] = {upper, lower,switchc,quit};

  while (1)
  {
      scanf("%c", &ch);
      getchar();
      int x = ch - 48; //ASCII value of 1 = 49
      //to validate our passing parameters

     f_array[x-1](mystring);
     //x-1 so that when input = 1, it accesses 0th index
     //eg, ch = 2 means f_array[2](mystring)
     //which is equivalent to lower(mystring)
  }

  free(mystring);
  //for dynamically allocated string

  return 0;
}
