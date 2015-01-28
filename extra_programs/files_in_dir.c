#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<dirent.h>
int main(int argc, char *argv[])
{
	DIR *dp;
	char ptr[100];
	struct dirent *dirp;
	if(argc < 2)
	{
		//by default taking it as current working directory		
		
		if(chdir("/home/student/Desktop/")<0)
		{
			printf("error in changing directory");
			return;	
		}
		getcwd(ptr,100);
		dp=opendir(ptr);
	}
	else
	{
		dp=opendir(argv[1]);	
	}
	

	
	while((dirp=readdir(dp))!=NULL)
	{

		printf("%s\n",dirp->d_name);
		

	}
	
	closedir(dp);
}
