#include <stdio.h>
#include <string.h>

int main()
{
    char str[81]; 
    
    while (1)
	{
        printf("Enter a string (or 'END' to exit): ");
        fgets(str, sizeof(str), stdin);
        
        str[strcspn(str, "\n")] = '\0';
        
        if (strcmp(str, "END") == 0)
            break; 
        
        for (int i = 0; str[i] != '\0'; i++) 
            str[i] = toupper((unsigned char)str[i]);
        
        printf("Uppercase: %s\n", str);
    }

    printf("Program terminated.\n");
    return 0;
}
