//Implement a program using SIGUSR1 and pause system call to synchronize and wait for signal
#include<stdio.h>
#include<signal.h>
#include <unistd.h>
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
void handler(int s)
{
	printf("handler\n");
}
int main()
{
	int pid;
	int status;
	
	pid=fork();
	
	
	if(pid==0)
	{
		signal(SIGUSR1,handler);
		pause();
		character("child bbbbbbbbbbbbbbbbbbb bbbbbbbbbbbbbbbbbbbbbbbbbbbbb\n");	
	}
	else
	{
		
		character("parent aaaaaaaaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaaaaaaaaaaa\n");
		kill(pid,SIGUSR1);
		wait(&status);
	}
	
	

}



