#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 80

char *process_string(char *line) 
{
    char *result = NULL;
    char *token;
    size_t length = 0;

    token = strtok(line, " ");  
    while (token != NULL) 
	{
        size_t token_length = strlen(token);
        result = realloc(result, length + token_length + (length > 0 ? 1 : 0) + 1);

        if (result == NULL)
		{
            printf("Memory allocation failed\n");
            return NULL;
        }

        if (length > 0) 
		{
            result[length] = '_';  
            length++;
        }

        strcpy(result + length, token);
        length += token_length;

        token = strtok(NULL, " ");
    }

    if (result != NULL) 
	{
        result[length] = '\0';
    }

    return result;
}

int main()
{
    char line[MAX_LINE_LENGTH + 1];  

    printf("Enter a line of text (max 80 characters): ");
    fgets(line, sizeof(line), stdin);

    line[strcspn(line, "\n")] = '\0';

    char *concatenated_string = process_string(line);

    if (concatenated_string != NULL) 
	{
        printf("Words in the string:\n");
        char *token = strtok(line, " ");
        while (token != NULL)
		{
            printf("%s\n", token);
            token = strtok(NULL, " ");
        }

        printf("Final concatenated string: %s\n", concatenated_string);

        free(concatenated_string);
    }

    return 0;
}

