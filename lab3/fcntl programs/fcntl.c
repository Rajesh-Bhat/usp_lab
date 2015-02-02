#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{	



	int fd1,val;
	if((fd1=open("a1.txt",O_RDWR|O_CREAT|O_APPEND,0644)) < 0)
	{
		printf("error\n");
		return;	
		
	}
	
	printf("readwrite:%d creat:%d append:%d\n",O_RDWR,O_CREAT,O_APPEND);
	if((val=fcntl(fd1,F_GETFL,0)) < 0)
	{
		printf("error\n");
		return;	
		
	}
	
	int accfg=val & O_ACCMODE;
	printf("accmode:%d\n",O_ACCMODE);
	printf("accfg:%d\n",accfg);
	if(accfg == O_WRONLY)
	{
		printf("WRITE\n");
			
		
	}
	if(accfg == O_RDONLY)
	{
		printf("READ ONLY\n");
			
		
	}
	if(accfg == O_RDWR)
	{
		printf("READ WRITE\n");
			
		
	}
	if(val & O_APPEND)
	{
		printf("APPEND\n");
			
		
	}

	printf("%d",val);

	

}
