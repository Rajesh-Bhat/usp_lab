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
	signal(SIGINT,SIG_IGN);
	//changing SIG_DFL terminates the program AND SIG_IGN ignores the signal
	while(1);
	pause();
	
}


