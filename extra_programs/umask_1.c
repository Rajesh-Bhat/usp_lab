#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>


int main()
{
	creat("d.txt",0644);
	umask(0044);
	creat("f",0777);

}

