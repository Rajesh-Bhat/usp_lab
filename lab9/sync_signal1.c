//Implement a program using SIGUSR1 and pause system call to synchronize and wait for signal
#include<stdio.h>
#include<signal.h>
#include <unistd.h>
#include <stdlib.h>



void err_quit(const char* x) 
{ 
    perror(x); 
    exit(1); 
}

void err_sys(const char* x) 
{ 
    perror(x); 
    exit(1); 
}

static volatile sig_atomic_t sigflag; /* set nonzero by sig handler */
static sigset_t newmask, oldmask, zeromask;

static void
sig_usr(int signo)   /* one signal handler for SIGUSR1 and SIGUSR2 */
{
    sigflag = 1;
}

void
TELL_WAIT(void)
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR)
        err_sys("signal(SIGUSR1) error");
    if (signal(SIGUSR2, sig_usr) == SIG_ERR)
        err_sys("signal(SIGUSR2) error");
    sigemptyset(&zeromask);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGUSR1);
    sigaddset(&newmask, SIGUSR2);

    /*
     * Block SIGUSR1 and SIGUSR2, and save current signal mask.
     */
    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        err_sys("SIG_BLOCK error");
}

void
TELL_PARENT(pid_t pid)
{
    kill(pid, SIGUSR2);              /* tell parent we're done */
}

void
WAIT_PARENT(void)
{
    while (sigflag == 0)
        sigsuspend(&zeromask);   /* and wait for parent */
    sigflag = 0;

    /*
     * Reset signal mask to original value.
     */
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        err_sys("SIG_SETMASK error");
}

void
TELL_CHILD(pid_t pid)
{
    kill(pid, SIGUSR1);             /* tell child we're done */
}

void
WAIT_CHILD(void)
{
    while (sigflag == 0)
        sigsuspend(&zeromask);  /* and wait for child */
    sigflag = 0;

    /*
     * Reset signal mask to original value.
     */
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        err_sys("SIG_SETMASK error");
}

void character(char a[])
{
	
	
	int i=0;
	while(a[i] != '\0')
	{
		
		printf("%c",a[i]);
		fflush(stdout);
		i++;
	}
}

int main()
{
	int pid;
	int status;
	TELL_WAIT();  /* set things up for TELL_xxx & WAIT_xxx */
	pid=fork();
	
	
	if(pid==0)
	{
		
		WAIT_PARENT();  
		character("child bbbbbbbbbbbbbbbbbbb bbbbbbbbbbbbbbbbbbbbbbbbbbbbb\n");	
		
	}
	else
	{
		
		character("parent aaaaaaaaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaaaaaaaaaaa\n");
		TELL_CHILD(pid);            /* tell child we're done */
		
	}
	
	

}



