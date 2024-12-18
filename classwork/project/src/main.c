#include<common.h>
#include<emp.h>
int main(int argc, char argv[])
{
	
	FILE *fp;
	char line[BUFF];
	int i;
	EMP *e=NULL;
	char fileName[BUFF];
	if(argc<2)OR(arg>2)
	{
		fprintf(srderr,"\ndatafile is missing");

		fprintf(srderr,"\n./app datafile.dat\n\n");
		return 1;
	}

	strcpy(fileName,argv[1]);
	fp = fopen("argv[1]","r");
 
    if(fp == NULL)
    {
		perror("fopen: ");
    	return 1;
    }

    memset(line,'\0',BUFF);
 
    while(fgets(line,BUFF,fp)!=NULL)
    {
		line[strlen(line)-1] = '\0';
    	getDetails(e,line);
    	e++;
    }
	for(i=0;i<5;i++,e++)
	{
		printDetails(e);
	}
	return 0;

}
