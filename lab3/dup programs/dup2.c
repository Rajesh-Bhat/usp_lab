#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{	



	int fd1,fd2;
	fd1=open("a.txt",O_WRONLY|O_CREAT,0644);
	fd2=dup2(1,fd1);//fd1,1
	write(fd1,"hello\n",strlen("hello\n"));
	write(1,"world\n",strlen("hello\n"));
	printf("%d %d",fd1,fd2);

}
