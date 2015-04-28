#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
int a=0;

void *fun(void *vargp)
{
   
    a++;
    printf("value of a is %d \n",a);
    return NULL;
}
  
int main()
{
    pthread_t tid1,tid2;
    
    pthread_create(&tid1, NULL,fun, NULL);
    pthread_create(&tid2, NULL,fun, NULL);
    pthread_join(tid2, NULL);
    printf("After Thread\n");
    exit(0);
}
