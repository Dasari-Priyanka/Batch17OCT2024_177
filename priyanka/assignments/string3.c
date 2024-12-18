#include <stdio.h>
#include <string.h>

void replaceVowels(char *word);

int main() 
{
    char word[41]; 

    printf("Enter a word (up to 40 characters): ");
    fgets(word, sizeof(word), stdin); 

    word[strlen(word)-1] = '\0';

    replaceVowels(word);

    printf("Updated word: %s\n", word);

    return 0;
}

void replaceVowels(char *word)
{
    int i, j;
    int length = strlen(word);
    char updated[81];  
    int index = 0;

    for (i = 0; i < length; i++) 
	{
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' ||
            word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U') 
		{
            updated[index++] = 'a';
            updated[index++] = 'y';
        }
		else 
		{
            updated[index++] = word[i];
        }
    }
    updated[index] = '\0'; 

    strcpy(word, updated);
}
