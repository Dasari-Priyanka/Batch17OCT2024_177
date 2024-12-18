#include <stdbool.h>
#include <stdio.h>
int main()
{
int i = 123;
short s = 98;
bool b = true;
char c = 'Y';
float d = 235.789;

       printf("\nb+c=%d",b+c);
     printf("\ns*i=%d",s * i);
     printf("\nc*d=%f",c * d);
     printf("\nc = c+b=%c",c+b);
       printf("\nd = d+c=%f",d+c);
       printf("\nb = -d=%d\n",b=-d);

    return 0;
}

