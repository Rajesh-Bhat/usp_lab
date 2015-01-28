//Write a program that creates a file with a 4K bytes free space. Such files are called files with holes.
// files with holes are also called as sparse files
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
    char buf1[]="before";
    char buf2[]="after"; 
    int fd,n;
    
    fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        printf("error in opening file\n");
        return;
    }
    
    n=write(fd,buf1,strlen("before"));
    
    if(n < 0)
	{
		printf("error in writing to file\n");
		return;
	}
    
    //creating 4K free space
    lseek(fd, 4*1024, SEEK_CUR);
    
    n=write(fd,buf2,strlen("after"));
    if(n < 0)
	{
		printf("error in writing to file\n");
		return;
	}
	
    //getting file size
    int file_size=lseek(fd,0, SEEK_CUR);
    
    //pointer to the beginning of the file
    lseek(fd,0, SEEK_SET);
	
	char buf[file_size];
	
	//reading from file
	read(fd,buf,file_size);
	
	
	
	//displaying the read contents
	//only contents which are before holes in a file are read.
	printf("%s\n",buf);
    close(fd);
    return 0;
}
