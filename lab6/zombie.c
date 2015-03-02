#include<stdio.h>
// zombie process no process to take exit status of child
main()
{
    int id;
    id=fork();

    if(id>0)
    {
        printf("Parent will sleep");
        sleep(10);
    }
    if(id==0)
        printf("I am child");
}
