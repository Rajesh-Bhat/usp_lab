//appending data to the existing fileand reading data from it
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main()
{

	char buf[100];
	gets(buf);
	int fd,n,file_size;
	fd=open("output.txt",O_RDWR|O_APPEND,0644);
	
	if(fd==-1)
	{

		printf("error in opening the file\n");
	}
	else
	{
		n=write(fd,buf,strlen(buf));
	}
	
	if(n < 0)
	{
		printf("error in writing\n");
		return;
	}
	
	file_size=lseek(fd,0,SEEK_CUR);
	// go the beginning of the file
	lseek(fd,0,SEEK_SET);
	
	read(fd,buf,file_size);
	
	printf("%s",buf);
	close(fd);



}
