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
		//exit(222);
		//abort();
		kill(getpid(),SIGSTOP);
	}
	else
	{
		int w=waitpid(cpid,&status,0);
		if(w==-1)
		{
			printf("wait failure\n");
		}
		
		if(WIFEXITED(status))
		{
			printf("process exited %d\n",WEXITSTATUS(status));
		}
		else if(WIFSIGNALED(status))
		{
			printf("signal%d\n",WTERMSIG(status));
		}
		else if(WIFSTOPPED(status))
		{
			printf("stop%d\n",WSTOPSIG(status));
		}
		else
		{
			printf("default\n");
		}
	}
}
