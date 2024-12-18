#include <stdio.h>
int main()
{
float cnt = 0;
int num = 1000;
 do 
 { 
  printf ("\n%d\n%f\n", num,cnt);
  num /= cnt;      
 } while (cnt ++); /* End of while */
return 0;
}

