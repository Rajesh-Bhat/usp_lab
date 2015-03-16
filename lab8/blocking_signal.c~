#include<stdio.h>
#include<signal.h>
#include <unistd.h>


void int_handler(int sig)
{
	printf("inside handler");
}
int main()
{
	sigset_t s,y;
	signal(SIGINT,int_handler);
	sigemptyset(&s);
	
	sigaddset(&s,SIGUSR1);
	sigaddset(&s,SIGALRM);
	sigaddset(&s,SIGINT);
	sigaddset(&s,SIGQUIT);
	
	sigprocmask(SIG_BLOCK,&s,NULL);
	sleep(10);
	sigprocmask(SIG_UNBLOCK,&s,NULL);
	
	//sigprocmask(SIG_SETMASK, &s, NULL)
	pause();
	
	
}
