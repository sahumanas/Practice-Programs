#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS          2
#define INVALID_RETURN_VALUE (-1)

int             shared_count = 0;
pthread_mutex_t shared_count_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  shared_count_cv   = PTHREAD_COND_INITIALIZER;

void thread_1(void *ptr)
{
//    char thread_name[15];

//    pthread_setname_np("even_thread");
//    pthread_getname_np(pthread_self(), thread_name, 15);

    while (1) {
        sleep(1);
        pthread_mutex_lock(&shared_count_lock);
        while (!((shared_count - 1) % 2)) {
            pthread_cond_wait(&shared_count_cv, &shared_count_lock);
            shared_count++;
            printf("shared_count = %d\n",shared_count);
        }
        pthread_cond_signal(&shared_count_cv);
        pthread_mutex_unlock(&shared_count_lock);
    }
}

void thread_2(void *ptr)
{
    char thread_name[15];

  //  pthread_setname_np("odd_thread");
//pthread_getname_np(pthread_self(), thread_name, 15);

    while (1) {
        sleep(1);
        pthread_mutex_lock(&shared_count_lock);
        while (!(shared_count % 2)) {
            pthread_cond_wait(&shared_count_cv, &shared_count_lock);
            shared_count++;
            printf("shared_count = %d\n", shared_count);
        }
        pthread_cond_signal(&shared_count_cv);
        pthread_mutex_unlock(&shared_count_lock);
    }
}

int 
main(int argc, char **argv)
{
    int i;
    int rc = INVALID_RETURN_VALUE;
    pthread_t thread[MAX_THREADS];
    pthread_t thread2;
    char thread_name[10];

//    pthread_setname_np("main");
//    pthread_getname_np(pthread_self(), thread_name, 10);

    pthread_create(&thread[0], NULL, thread_1, NULL);
    pthread_create(&thread[1], NULL, thread_2, NULL);


    for(i = 0; i < MAX_THREADS; i++) {
        pthread_join(thread[i], NULL);
    }

    /*
     * Cleanup
     */
    rc = pthread_mutex_destroy(&shared_count_lock);

    if (rc) {
        printf("Unable to destroy lock = %s\n", thread_name);
    }

    rc = pthread_cond_destroy(&shared_count_cv);

    if (rc) {
        printf("Unable to destroy cv = %s\n", thread_name);
    }

    return 0;
}
