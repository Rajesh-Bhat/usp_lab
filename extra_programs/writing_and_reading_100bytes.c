//WRITING 100 BYTES OF DATA TO A FILE AND THEN READING THE DATA
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main()
{

	char buf[100]="welcome to usp class";
	int fd,n,bytes_written;
	fd=open("output.txt",O_RDWR|O_CREAT,0644);
	
	if(fd==-1)
	{

		printf("error in opening the file");
	}
	else
	{
		write(fd,buf,100);
	}

	lseek(fd,0,SEEK_SET);
	n=read(fd,buf,100);
	

	
	//displays 0 bytes read because file pointer is at the end of file if lseek is not done
	printf("number of bytes read from file is %d\n",n);
	close(fd);



}
