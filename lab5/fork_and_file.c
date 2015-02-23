#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{

	
	int fd=open("temp.txt",O_CREAT|O_RDWR|O_TRUNC,0666);
	int pid=fork();
	char buf[7]="rajesh";
	int s;
	if(pid==0)
	{
		write(fd,buf,7);
		printf("finished writing\n");
		
	}
	else
	{
		wait(s);
		char newbuf[7];
		lseek(fd,0,SEEK_SET);
 		read(fd,newbuf,7);
		printf("reading from file\n");
		printf("%s\n",newbuf);

	}


}
