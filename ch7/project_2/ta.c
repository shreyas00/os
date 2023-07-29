#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_STUDENTS 5

void * ta_t(void * param);
void * st_t(void * param);

pthread_t students[NUM_STUDENTS];
pthread_t ta;

pthread_mutex_t mutex;
int waiting_students = 0, count = 10;
sem_t sem;

int main(void)
{
    srand(4);

    sem_init(&sem, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&ta, NULL, &ta_t, NULL);

    for(int i = 0; i < NUM_STUDENTS; i++)
    {
        pthread_create(&students[i], NULL, &st_t, NULL);
    }

    while (count > 0)
    {
        /* code */
    }
    
    return 0;
}

void * ta_t(void * param)
{
    while (count-- > 0)
    {
        sem_wait(&sem);
        printf("Helping student\n");
        
        pthread_mutex_lock(&mutex);
        waiting_students--;
        pthread_mutex_unlock(&mutex);
        sleep((int)((double)rand() / ((double)RAND_MAX / 2)));
    }
}

void * st_t(void * param)
{
    while (count > 0)
    {
        sleep((int)((double)rand() / ((double)RAND_MAX / 4)));
        pthread_mutex_lock(&mutex);
            printf("St\n");
        if(waiting_students < 3)
        {
            waiting_students++;
            pthread_mutex_unlock(&mutex);
            sem_post(&sem);
        }
        else{
            pthread_mutex_unlock(&mutex);
        }
    }
    
}