#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void b(void)
{
	printf("hello bbbbbbbbbbbb\n");

}


void c(void)
{
	printf("hello cccccccccccccccc\n");

}
int main()
{

	int a,i;
	// knowing sys configurations GETTING MAX VALUE  OF ATEXIT
	a=sysconf(_SC_ATEXIT_MAX);
	printf("atexitmax=%d\n",a);

	//
	i=atexit(b);
	i=atexit(c);

	if(i!=0)
	{
		printf("error\n");
		exit(1);
	}
	exit(0);

}



