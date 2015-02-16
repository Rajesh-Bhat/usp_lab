#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
main(int agrc, char *argv[])
{

 	symlink(argv[1],argv[2]);
 	
 	struct stat buf;
 	lstat(argv[2],&buf);
 	
 	char *link=(char*)malloc(buf.st_size);
 	
 	readlink(argv[2],link,buf.st_size);
 	
 	printf("%s",link);
 

} 


