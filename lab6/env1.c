#include<stdio.h>
#include<stdlib.h>
int main()
{

	const char *pathvar=getenv("HOME");
	printf("home =%s\n",pathvar);

	// can change only the env variable of child process
	setenv("HOME","/home/rajesh",1);
	const char *pathvar1=getenv("HOME");
	printf("home =%s\n",pathvar1);

	
	
	// changing the login name
	// any changes made is only for the child process
	static char *var="LOGINNAME=rajesh";
	putenv(var);	
	const char *pathvar2=getenv("LOGINNAME");
	printf("login name=%s\n",pathvar2);

	

}
