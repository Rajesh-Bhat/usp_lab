#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{

	int fd;
	fd=dup(1);
	write(1,"hello\n",strlen("hello\n"));
	write(fd,"hello\n",strlen("hello\n"));
	printf("%d",fd);

	



}
