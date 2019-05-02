/*
JTSK-320112
6.4.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fptr; //file ptr
    char fname[50]; //file name
    char buff[50]; //buffer
    char username[50], funame[50];
    char password[50], fpw[50];

    //input filename
    fgets(buff, sizeof(fname), stdin);
    sscanf(buff, "%s",&*fname);
    //&*fname because grader's compiler says: "%s" expects &*fname since fname datatype char[50].
    fname[strlen(fname)] = '\0';

    fptr = fopen(fname,"r");

    //file opening error
    if (fptr == NULL)
    {
        perror("Error opening file\n");
       // return -1;
    }

    //sets fptr at end of file
    fseek(fptr, 0L, SEEK_END);
    int f_size = ftell(fptr); //gives size of file(how many bytes from position 0 to end of file)
    int offset = 0;

    while (1)
    {
        rewind(fptr); //sets fptr to beginning during every loop

        //username from input
        fgets(buff, sizeof(username), stdin);
        sscanf(buff, "%[^\n]", &*username);
        username[strlen(username)] = '\0';

        int x = strcmp(username,"exit");
        printf("%d",x);

        //ending loop condition
        if (username[0] == 'e' && username[1] == 'x' && username[2] == 'i' && username[3] == 't')
        {
            printf("Exiting ...\n");
            break;
        }

        //password from user
        fgets(buff, sizeof(password), stdin);
        sscanf(buff, "%[^\n]", &*password);
        password[strlen(password)] = '\0';

        int repeat = 0;

        //repeats until match found/wrong password/end of file reached
        while (repeat == 0)
        {

            offset = ftell(fptr);
            //printf("%d offset1\n", offset);
            fseek(fptr, offset, SEEK_SET);
            fscanf(fptr, "%s\n", &*funame);

            int check = strcmp(funame,username);


            //if input username exists in database,
            if (check == 0)
            {
                offset = ftell(fptr);
                //printf("%d offset2\n", offset);
                fseek(fptr, offset, SEEK_SET);
                fscanf(fptr, "%s\n", &*fpw);

                int check2 = strcmp(fpw, password);
                //check if password entered is correct

                if (check2 == 0)
                    printf("Access to user %s is granted.\n", username);
                else
                    printf("Access to user %s is denied.\n", username);

                repeat = 1;
                //loop to enter other usernames
            }
            else
            {
                //if reached end of file and username not found
                if (ftell(fptr) == f_size)
                {
                    repeat = 1;
                    printf("This user doesn't exist in database\n");

                }
                //else, checks for other usernames in database to see if it exists

            }
        }

    }

    fclose(fptr);//close file

    return 0;
}
