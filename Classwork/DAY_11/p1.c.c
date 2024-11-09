/*
Scanning and Printing the string
*/

#include <stdio.h>

int main()
{
    char Name[5];
    int i;
    for(i=0;i<5;i++)
        scanf("%c",&Name[i]);
    for(i=0;i<5;i++)
        printf("\n%c=%d\n",Name[i],Name[i]);
    scanf("%s",Name);
    printf("%s",Name);
    printf("\n\n");
    
    return 0;
}