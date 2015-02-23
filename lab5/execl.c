#include<stdio.h>
#include<unistd.h>


int main()
{
	int pid=fork();
	
	if(pid==0)
	{
		//execl("/bin/cat","cat","/home/rajesh/cube.py",(char*)0);
		//execl("/bin/ls","ls","/home/rajesh/",(char*)0);
		//execl("/bin/date","date",(char*)0);
		
		execl("/bin/ps","ps","-u","rajesh",(char*)0);
		printf("child process\n");
		
	}
	else
	{
		printf("parent process\n");
		
		
	}
	
	
	
}
