#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>



int main()
{
	
	creat("d.txt",0644);
	link("d.txt","c.txt");
	unlink("d.txt");// removes the file

}
