#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
	char *buf[100];
	//demonstrating std inp and output.
	//insted of using STDIN_FILENO  we can use 0 and 1 for STDOUT_FILENO
	int a=read(0,buf,100);
	write(STDOUT_FILENO,buf,a);
	
	return 0;
}
