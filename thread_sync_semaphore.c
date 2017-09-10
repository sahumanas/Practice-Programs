#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>  /* Semaphore */

#define THREADS 3
sem_t sem1;
sem_t sem2;
sem_t sem3;


void * callback_thread1 (void* data)
{
	while (1){
	 sem_wait(&sem1);       /* down semaphore */
	 printf("I m in thread 1 \n");
	 sem_post(&sem2);       /* down semaphore */
	}
}
	
void * callback_thread2 (void* data)
{
	while (1){
	 sem_wait(&sem2);       /* down semaphore */
	 printf("I m in thread 2 \n");
	 sem_post(&sem3);       /* down semaphore */
	}
}

void * callback_thread3 (void* data)
{
	while (1){
	 sem_wait(&sem3);       /* down semaphore */
 	 printf("I m in thread 3 \n");
	 sem_post(&sem1);       /* down semaphore */
	}
}

int main(int argc, char **argv)
{

	pthread_t tid[THREADS];
	
	/*
	As sema phore 2 and 3 needs to be bloacked on earlier signal from the thread 
	i.e. 2 is waiting for 1 and 3 is waiting on 2 . We have initialised them to 0 
	Ref -   https://www.quora.com/How-is-initial-value-of-semaphore-decided
		https://stackoverflow.com/questions/14793416/zero-permit-semaphores
	*/
	sem_init(&sem1, 0, 1);
	sem_init(&sem2, 0, 0);
	sem_init(&sem3, 0, 0);
        
	pthread_create(&tid[2], NULL,callback_thread3, NULL);
	pthread_create(&tid[0], NULL,callback_thread1, NULL);
	pthread_create(&tid[1], NULL,callback_thread2, NULL);

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	
	sem_destroy(&sem1);
	sem_destroy(&sem2);
	sem_destroy(&sem3);
	 
	return 0;
}


