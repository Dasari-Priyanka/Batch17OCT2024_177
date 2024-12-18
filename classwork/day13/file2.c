#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	 FILE *fd=NULL;
	 FILE *fd1=NULL;
	 char ch;
	 fd =fopen("Test1.txt","r");
	 fd1 = fopen("Test2.txt","w");

	 if(fd==NULL)
	 {
	 	perror("fopen: ");
		printf("\n%p\n\n",fd);
		exit(1);
	 }
	 printf("\nopened the file successfully %p\n\n",fd);
	 if(fd1==NULL)
	 {
	 	perror("fopen: ");
        printf("\n%p\n\n",fd);
        exit(1);
     }
     printf("\nopened the file successfully %p\n\n",fd);

	 fclose(fd);
	 fclose(fd1);

	 
	 while((ch=fgetc(fd))!=EOF)
	 {
	 	fputc(ch,fd1);
	 }
	 fclose(fd);
	 return 0;
}
