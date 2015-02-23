#include<stdio.h>
#include<unistd.h>


int main()
{
	int pid=fork();
	
	if(pid==0)
	{
		printf("child:%d %d\n",getpid(),getppid());
	}
	else
	{
		printf("parent:%d %d\n",pid,getppid());
	}
	
	
	
}
