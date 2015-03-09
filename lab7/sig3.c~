//wap to catch SIGUSR1,SIGUSR2 SIGKILL SIGSTOP SIGTERM signals.
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void sighandler(int signo)
{
	if(signo==SIGUSR1)
	{
		printf("usr1 signal caught\n");
	}
	else if(signo==SIGUSR2)
	{
		printf("usr2 signal caught\n");
	}
	else if(signo==SIGKILL)
	{
		printf("SIGKILL signal caught\n");
	}
	else if(signo==SIGSTOP)
	{
		printf("SIGSTOP signal caught\n");
	}
	else if(signo==SIGTERM)
	{
		printf("SIGTERM signal caught\n");
	}
	
}
int main()
{
	signal(SIGUSR1,SIGINT);
	signal(SIGUSR2,SIGINT);
	signal(SIGKILL,SIG_IGN);//CANNOT BE IGNORED OR CAUGHT
	signal(SIGSTOP,SIG_IGN);//CANNOT BE IGNORED OR CAUGHT
	signal(SIGTERM,SIGINT);
	while(1);
	pause();
	
}

