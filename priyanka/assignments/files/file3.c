/****************************************************************************************************
*   FUNCTION NAME : operation.c
*   DESCRIPTION   : this function will open the input file "input.txt" which has
*   strings 1 per line and
*   copy  the data in a dynamic array and display its content
****************************************************************************************************
*****************************MACROS**************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 80
#define FAILURE 0
//taking the input from a file

int getFileString(char ***text,
                  char *input
                 )
{
    FILE *fp;

    int textCount = 0,
        len = 0,i;

    char buff[MAX_SIZE];

    fp = fopen("input.txt", "r");

    if(fp != NULL)
    {
        *text = (char**)malloc(sizeof(char) * (MAX_SIZE + 1));
        if(text != NULL)
        {
            while(fgets(buff, MAX_SIZE, fp) != NULL)
            {
                len = strlen(buff) + 1;
                (*text)[textCount] = (char*)malloc(sizeof(char*) * len);

                if((*text)[textCount] != NULL)
                {
                    strcpy((*text)[textCount], buff);

                    len -= 2;
                    if( ((*text)[textCount])[len] == '\n')
                    {
                        ((*text)[textCount])[len] = '\0';
                    }

                    textCount += 1;
                }
            }
        }
        else
        {
            printf("\nNot able to allocate memory");
            return FAILURE;
        }
        fclose(fp);
        return textCount;

    }
    else
    {
        printf("\nFile cannot be opened");
    }
}

void display(char **arr, int num)
{
    //TBD Traverse the arr input and display all strings
    int i;
    for(i=0;i<num;i++)
    {
        printf("%s\n",arr[i]);
    }

}


int main(int argc, char *argv[])
{
    char **text = NULL;

    int textCount = 0,i;
    if(argc !=  3)
    {
        textCount = getFileString(&text, argv[1]); //function calling getfilestring to take an input from a file input.txt
        display(text,textCount);
    }
    else
    {
        printf("\nEntered else\n");
    }
    for(i=0;i<textCount;i++)
    {
        free(text[i]);
    }
    free(text);


    return FAILURE;
}

