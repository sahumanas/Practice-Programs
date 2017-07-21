#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int MAX = 10;
int count = 0;

pthread_mutex_t mutex;
pthread_cond_t cond;

void *even(void *arg)
{
    while(count < MAX) {
        pthread_mutex_lock(&mutex);
        while(count % 2 != 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("%d ", count++);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
    }
    pthread_exit(0);
}

void *odd(void *arg)
{
    while(count < MAX) {
        pthread_mutex_lock(&mutex);
        while(count % 2 != 1) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("%d ", count++);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
    }
    pthread_exit(0);
}

int main()
{
    pthread_t th[2];

    pthread_mutex_init(&mutex, 0);
    pthread_cond_init(&cond, 0);

    pthread_create(&th[0], 0, &even, NULL);
    pthread_create(&th[1], 0, &odd, NULL);

    pthread_join(th[0], 0);
    pthread_join(th[1], 0);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return  0;
}


