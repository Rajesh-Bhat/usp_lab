//http://developeriq.in/articles/2012/may/30/interprocess-communicationipc-programs-in-c-in-ubu/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/msg.h>
#define  MAX_TEXT 512

struct my_msg_st
{
	long int my_msg_type;
	char some_text[MAX_TEXT];
};

int main()
{
	int running = 1;
	struct my_msg_st some_data;
	int msgid;
	char buffer[BUFSIZ];

	// creating a message queue
	msgid = msgget( (key_t)1234,0666 | IPC_CREAT);
	if (msgid == -1)
	{	
		printf("failed to create:\n");
		exit(0);
	}
	
	while(running)
	{
		printf("Enter Some Text: ");
		fgets(buffer, BUFSIZ, stdin);
		some_data.my_msg_type = 1;
		strcpy(some_data.some_text, buffer);

		//adding message to message queue
		if(msgsnd(msgid, (void *)&some_data, MAX_TEXT, 0) == -1)
		{
			printf("msgsnd failed\n");
			exit(0);
		}
		
		if(strncmp(buffer, "end", 3) == 0)
		{
			running = 0;
		}
	}


	exit(EXIT_SUCCESS);
}
