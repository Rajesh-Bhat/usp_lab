#include<stdio.h>
#include<unistd.h>


int main(int argc,char **argv)
{
	int pid=fork();
	int i;
	
	for(i=0;i<argc;i++)
	{
		printf("%s\n",argv[i]);
	}

	extern char **environ;
	i=0;
	while(environ[i])
	{

		printf("%s\n",environ[i++]);
	}
		
		
		

	
	
	
}
