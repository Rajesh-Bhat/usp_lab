#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("gid %d, egid %d\n",getgid(),getegid());
	int ret=setegid(600);// setgid changes both id and eid
	// setegid changes only egid
	if(ret <0)
	{
		printf("error in setuid\n");
	}
	printf("gid %d, egid %d\n",getgid(),getegid());
	
}
