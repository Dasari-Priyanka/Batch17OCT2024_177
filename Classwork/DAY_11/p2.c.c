/*
comparing two string
*/
#include <stdio.h>
#include <string.h>
int main()
{
    char s1[20], s2[20];
    scanf("%s%s",s1,s2);
    int ret=0;
    printf("\ns1=%s\ts2=%s",s1,s2);
    ret = strcmp(s1,s2);
    printf("\nRet=%d",ret);

}
