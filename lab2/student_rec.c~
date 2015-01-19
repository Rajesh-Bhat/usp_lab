#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
struct student
{
	char name[100];
	char usn[10];	
};

int main()
{

	
	
	int fd,file_size,i;
	fd=open("student_rec.txt",O_RDWR|O_APPEND,0644);
	
	int num_students;
	printf("enter number of students:");
	scanf("%d",&num_students);
	
	if(fd==-1)
	{

		printf("error in opening the file\n");
	}
	else
	{
		struct student s[num_students];
		for(i=0;i<num_students;i++)
		{
			
			printf("enter name:");
			//gets(s[i].name);
			scanf("%s",s[i].name);
			
			printf("enter usn:");
			scanf("%s",s[i].usn);
			
			//gets(s[i].usn);
			write(fd,&s[i], sizeof(struct student));
			
			
		}
	}
	
	
	file_size=lseek(fd,0,SEEK_CUR);
	
	int num_structs=file_size/110;
	
	struct student s1[num_structs];
	// go to the beginning of the file
	lseek(fd,0,SEEK_SET);
	
	//reading from the textfile
	read(fd,&s1,file_size);
	
	for(i=0;i<num_structs;i++)
	{
		printf("*********** student %d ***********\n",i+1);
		printf("%s\n",s1[i].name);
		printf("%s\n",s1[i].usn);
		
	}
	close(fd);



}
