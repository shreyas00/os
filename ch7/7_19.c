#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define NUM_THREADS 100

sem_t sem;
pthread_mutex_t mutex;
int wait_count = 0;

void *sim(void *param);

void init(int N);
void barrier_point(void);

int main(void)
{

    pthread_t tid[100];
    pthread_attr_t attr;

    sem_init(&sem, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    init(20);

    pthread_attr_init(&attr);

    for(int i = 0; i < 100; i++)
    {
        pthread_create(&tid[i], &attr, &sim, NULL);
    }

    for(int i = 0; i < 100; i++)
    {
        pthread_join(tid[i], NULL);
    }
}

void *sim(void *param)
{
    printf("Wait\n");

    barrier_point();

    printf("Done\n");
}

void init(int N)
{
    wait_count = N;
}

void barrier_point(void)
{
    pthread_mutex_lock(&mutex);
    if (wait_count > 1)
    {
        wait_count--;
        pthread_mutex_unlock(&mutex);
        sem_wait(&sem);
    }
    else
    {
        pthread_mutex_unlock(&mutex);
    }
   
    sem_post(&sem);
}
