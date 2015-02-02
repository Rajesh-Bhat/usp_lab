#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{	



	int fd1,fd2;
	fd1=open("a1.txt",O_WRONLY|O_CREAT,0644);
	fd2=open("a2.txt",O_WRONLY|O_CREAT,0644);

	dup2(fd1,fd2);// writes to a1.txt
	write(fd1,"hello\n",strlen("hello\n"));
	write(fd2,"world\n",strlen("hello\n"));
	printf("%d %d",fd1,fd2);

}
