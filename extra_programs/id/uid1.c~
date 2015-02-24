#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("uid %d, euid %d\n",getuid(),geteuid());
	int ret=setuid(600);
	if(ret <0)
	{
		printf("error in setuid\n");
	}
	printf("uid %d, euid %d\n",getuid(),geteuid());
	
}
