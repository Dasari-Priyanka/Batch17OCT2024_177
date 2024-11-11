/*
strtok();
*/
#include <stdio.h>
#include <string.h>
int main()
{
    char *ptr = NULL;
    char s1[400], s2[20];
    printf("\nEnter the line with delimiter\n");
    scanf("%[^\n]s",s1);
    ptr = strtok(s1,",");
    printf("\nptr =%s",ptr);
    
    
    printf("\n\n");
    

}
