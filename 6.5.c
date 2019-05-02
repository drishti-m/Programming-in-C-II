/*
JTSK-320112
6.5.c
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    getchar();

    char *fnames[n];

    for (int i = 0; i < n; i++)
    {
        fnames[i] = (char*)malloc(255*sizeof(char));
        fgets(fnames[i], 255, stdin);
        fnames[i][strlen(fnames[i])-1] = '\0';
    } //inputs file names and stores in array

    FILE *output;
    output = fopen("output.txt", "wb"); //ptr to output file //binary mode

    //if opening fails, prg should exit
    if(output == NULL)
    {
        fprintf(stderr, "Cannot open file!\n");
        exit(1);
    }

    printf("Concating the content of %d files ...\nThe result is:\n", n);

    for (int i = 0; i < n; i++)
    {
        char *my_buff;
        //buffer to intermediately store content of files

        FILE *fptr;
        fptr = fopen(fnames[i], "rb"); //binary mode

        if(fptr == NULL)// file opening error
        {
            fprintf(stderr, "Cannot open file!\n");
            exit(1);
        }

        //we need file size to dynamically allocate buffer
        int buff_temps = 0;
        fseek(fptr, 0, SEEK_END);
        int file_size = ftell(fptr);

        //resetting fptr to beginning
        fseek(fptr, 0, SEEK_SET);
        my_buff = (char*)malloc(64+1);
        //allocating 64 bytes for character and 1 for '\0'

        while (buff_temps < file_size)
        {

            fread(my_buff, sizeof(char), 64, fptr); //reads 64 bytes from fptr position and store in my_buff
            //64 chunks of size 1
            printf("%s", my_buff);

            //if current loop is the last loop for one file, add '\n' to buffer
            if ((file_size - buff_temps) <= 64)
            {

                strcat(my_buff, "\n");
                fwrite(my_buff, sizeof(char) * strlen(my_buff),1, output);
            }

            else
                fwrite(my_buff, sizeof(char)*strlen(my_buff),1, output); //writing buff to output file
            /*parameters explained:
            my_buff = pointer to array of elements to be written
            sizeof(char) * strlen= size in bytes of each element to be written
            1 = 1 chunk
            output = ptr to file object with output stream
            1 chunk of size 64 */


            if ((buff_temps+64) >= file_size)
            {
                buff_temps = file_size;
                my_buff[file_size-64] = '\0';
            }//in case of files that have sizes that aren't multiple of 64

            else
            {

                buff_temps = buff_temps + 64;
            }

            fseek(fptr, buff_temps,SEEK_SET);
            //shifting ptr to 64 bytes forward from last loop

        }
        printf("\n");

        free(my_buff);//deallocating
        fclose(fptr);

    }

    // memory deallocation
    for(int i = 0; i < n; i++)
    {
        free(fnames[i]);
    }

    fclose(output);
    printf("The result was written into output.txt\n");

    return 0;
}
