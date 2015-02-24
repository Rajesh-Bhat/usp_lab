#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<signal.h>
int main()
{
	int cpid=fork();
	int status;
	if(cpid==-1)
	{
		printf("fork error\n");
	}
	else if(cpid==0)
	{
		printf("child process\n");
		printf("pid:%d ppid:%d\n",getpid(),getppid());
		kill(getpid(),9);
	}
	else
	{
		waitpid(cpid,&status,0);
		printf("parent process %d\n",getpid());
		//kill(getpid(),9);
	}
}
