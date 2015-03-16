#include<stdio.h>
#include<signal.h>
#include<unistd.h>

static void handler(int signum)
{
    /* Take appropriate actions for signal delivery */
    printf("insided handler\n");
}

int main()
{
	struct sigaction sa;
	
	sa.sa_handler = handler;
	if (sigaction(SIGINT, &sa, NULL) == -1)
    {	
    	printf("error\n");
    }
    pause();
	
}
