#include<stdio.h>
#include<unistd.h>


int main()
{
	int pid=fork();
	
	if(pid==0)
	{
		char* arg[]={"ls","-l",NULL};
		execv("/bin/ls",arg);
		printf("child process\n");
		
	}
	else
	{
		printf("parent process\n");
		
		
	}
	
	
	
}
