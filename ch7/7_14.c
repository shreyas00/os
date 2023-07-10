#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 100
void *pid_sim(void *param);

#define MIN_PID 300
#define MAX_PID 5000
#define BITMAP_SIZE (MAX_PID - MIN_PID)

int pid_bitmap[BITMAP_SIZE] = {0};
pthread_mutex_t mutex;

void release_pid(int pid);
int allocate_map(void);
int allocate_pid(void);

int main(void)
{
    srand(1);


    allocate_map();

    pthread_t tids[NUM_THREADS];
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    /* create and initialize the mutex lock */
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&tids[i], &attr, &pid_sim, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(tids[i], NULL);
    }

    printf("Allocate PID %d\n", allocate_pid());
}

void *pid_sim(void *param)
{
    int pid = allocate_pid();

    printf("Allocate PID %d\n", pid);

    sleep((int)((double)rand() / ((double)RAND_MAX / 10)));

    release_pid(pid);
    printf("Release PID %d\n", pid);
}

int allocate_map(void)
{
    int status = 0;
    for (int i = 0; i < BITMAP_SIZE; i++)
    {
        pid_bitmap[i] = 0;
    }
    return 0;
}

int allocate_pid(void)
{
    int i = 0;
    int pid = -1;
    /* acquire the mutex lock */
    pthread_mutex_lock(&mutex);
    while(i < BITMAP_SIZE)
    {
        if (pid_bitmap[i] == 0)
        {
            pid_bitmap[i] = 1;
            pid = i + MIN_PID;
            break;
        }
        else
        {
            i++;
        }
    }
    pthread_mutex_unlock(&mutex);
    return pid;
}

void release_pid(int pid)
{
    if (pid >= MIN_PID && pid <= MAX_PID)
    {
        /* acquire the mutex lock */
        pthread_mutex_lock(&mutex);
        pid_bitmap[pid - MIN_PID] = 0;
        pthread_mutex_unlock(&mutex);
    }
}