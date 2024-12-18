#include <stdio.h>
#include <string.h>

int tokenise(char *arr);

int main() 
{
    char input[100];

    printf("Enter a line of text: ");
    fgets(input, sizeof(input), stdin); 
	input[strlen(input)-1]='\0';
    int numTokens = tokenise(input);
    printf("\nTotal number of tokens: %d\n", numTokens);

    return 0;
}

int tokenise(char *arr) 
{
    char *token;
    int count = 0;

    token = strtok(arr, " ");  

    while (token != NULL)
	{
        printf("Token %d: %s\n", count + 1, token); 
        count++; 
        token = strtok(NULL, " "); 
    }

    return count;  
}
