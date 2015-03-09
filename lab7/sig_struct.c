#include <stdio.h>
#include <unistd.h>
#include <signal.h>
struct hello
{
	int a;
	int b;
	int c;
}data;


void sighandler(int sig)
{
	printf("%d\n",data.a);
	printf("%d\n",data.b);
	printf("%d\n",data.c);
}
int main()
{
	struct hello zeros={0,0,2};
	struct hello ones={1,1,3};
	
	signal(SIGALRM,sighandler);	
	alarm(2);
	
	while(1)
	{
		data=ones;
		data=zeros;
	}
	
	
}
