#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>

int main()
{
	//creat("chmod1.txt",0164);
	//system("ls -l");	
	//chmod("chmod1.txt",0644);
	
	
	// adding and removing permissions
	// negation is used for removing permission
	creat("chmod2.txt",0444);
	struct stat buf;
	int val;
	stat("chmod2.txt",&buf);
	val=buf.st_mode& ~ S_IRGRP;
	chmod("chmod2.txt",val);

	
	
}

