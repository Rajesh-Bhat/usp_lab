#include<stdio.h>
#include<unistd.h>


int main(int argc,char **argv)
{
	int pid=fork();
	int i;
	

	char* envp[]={"USER=abc","PATH=/tmp",NULL};

	execle("/home/student/Desktop/attachments/env","env","hello","class",(char*)0,envp);
	
	
	
}
