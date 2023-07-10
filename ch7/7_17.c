#include "pthread.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define TOTAL_POINTS 50000
#define NUM_POINTS_PER_THREAD 100
#define NUM_THREADS (TOTAL_POINTS / NUM_POINTS_PER_THREAD)

int points_inside = 0;
pthread_mutex_t mutex;

void *get_rand(void *param);

int main(void)
{
    srand(1);
    
    pthread_t tid[NUM_THREADS];
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_mutex_init(&mutex, NULL);

    for(int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&tid[i], &attr, &get_rand, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(tid[i], NULL);
    }
    

    double pi;
    pi = (4 * points_inside) / (double)TOTAL_POINTS;
    printf("Pi is %f\n", pi);
}

void * get_rand(void * param)
{
    int i = NUM_POINTS_PER_THREAD;
    double x,y;
    
    while (i-- > 0)
    {
        x = ((double)rand() / ((double)RAND_MAX / 2)) - 1.0f;
        y = ((double)rand() / ((double)RAND_MAX / 2)) - 1.0f;
        if (sqrt((x*x) + (y*y)) <= 1)
        {
            pthread_mutex_lock(&mutex);
            points_inside++;
            pthread_mutex_unlock(&mutex);
        }
    }
    
}