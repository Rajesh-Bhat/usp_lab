#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>


main(int argc, char *argv[])
{
	if(argc<2)
	{
		printf("error");
		exit(1);
	}
	struct stat buf;

	if(stat(argv[1],&buf)<0)
	{
		printf("stat error");
	}

	if(S_ISREG(buf.st_mode))
	{
		printf("REGULAR FILE");

	}

	if(S_ISDIR(buf.st_mode))
	{
		printf("DIR");

	}

	if(S_ISCHR(buf.st_mode))
	{
		printf("CHARACTER");
		// /dev/tty1
	}
	if(S_ISBLK(buf.st_mode))
	{
		printf("BLK FILE");
		// /dev/sda1
	}

	if(S_ISFIFO(buf.st_mode))
	{
		printf("FIFO");
		//mkfifo xyz
	}

	if(S_ISSOCK(buf.st_mode))
	{
		printf("SOCK");
		// /dev/log

	}
}
