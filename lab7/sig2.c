#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void sighandler(int signal)
{
	printf("signal is caught\n");
	//exit(0);
}

int main()
{
	signal(SIGALRM,sighandler);
	//changing SIG_DFL terminates the program AND SIG_IGN ignores the signal
	alarm(2);
	pause();
	
}
