#include<stdio.h>
#include<unistd.h>


int main()
{
	int pid=fork();
	
	if(pid==0)
	{
		execlp("date","date",(char*)0);
		printf("child process\n");
		
	}
	else
	{
		printf("parent process\n");
		
		
	}
	
	
	
}
