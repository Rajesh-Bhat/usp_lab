
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void sighandler(int signo)
{
	printf("%d\n",getpid());
	
}
int main()
{
	//before fork include alarm :caught by parent
	//cleared for child
	int pid=fork();
	//its caught by both parent and child
	//copied for both child and the parent
	alarm(2);
	if(pid==0)
	{
		
		signal(SIGALRM,sighandler);	
		printf("child:%d\n",getpid());
		pause();
	}
	else
	{
	
		signal(SIGALRM,sighandler);
		printf("parent:%d\n",getpid());
		pause();
	}
	
	
	
		
	
}

