#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

int MAX = 10;
int count = 0;

sem_t sem;

void *even(void *arg)
{
    while(count < MAX) {
        sem_wait(&sem);
        while(count % 2 == 0) {
            printf("%d ", count++);
        }
    }
    pthread_exit(0);
}

void *odd(void *arg)
{
    while(count < MAX) {
        while(count % 2 != 0) {
            printf("%d ", count++);
        }
        sem_post(&sem);
    }
    pthread_exit(0);
}

int main()
{
    pthread_t th1[2];

    sem_init(&sem,0,1);
    pthread_create(&th[0], 0, &even, NULL);
    pthread_create(&th[1], 0, &odd, NULL);

    pthread_join(th[0], 0);
    pthread_join(th[1], 0);

    sem_destroy(&sem);
    return  0;
}
