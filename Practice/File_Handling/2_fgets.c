/**
 * C program to read a file and display file contents character by character using fgetc() 
 */

#include <stdio.h>
#include <stdlib.h>


int main()
{
    /* File pointer to hold reference to our file */
    FILE * fPtr;
    FILE * fptr2;

    char* ch;

    /* 
     * Open file in r (read) mode. 
     * "data/file1.txt" is complete file path to read
     */
    fPtr = fopen("text.txt", "r");
    fptr2= fopen("copy.txt","w");
    /* fopen() return NULL if last operation was unsuccessful */

    if(fPtr == NULL || fptr2==NULL)
    {
        /* Unable to open file hence exit */
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }

    /* File open success message */
    printf("File opened successfully. Reading file contents character by character. \n\n");
    char character;

    do 
    {
        /* Read single character from file */
        fgets(ch,50,fPtr);

        fputs(ch, fptr2);
        character=fputc(1,fPtr);

        
        /* Print character read on console */
        //putchar(ch);

    } while(character != EOF); /* Repeat this if last read character is not EOF */

    /* Done with this file, close file to release resource */
    fclose(fPtr);
    fclose(fptr2);

    return 0;
}