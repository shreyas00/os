/**
 * Implementation of thread pool.
 */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include "threadpool.h"

#define QUEUE_SIZE 10
#define NUMBER_OF_THREADS 3

#define TRUE 1

// this represents work that has to be 
// completed by a thread in the pool
typedef struct 
{
    void (*function)(void *p);
    void *data;
}
task;

typedef struct
{
    task t;
    int *next;
} t_queue;

t_queue *first, *last;



// the worker bee
pthread_t bee[NUMBER_OF_THREADS];

// mutex and semaphores
pthread_mutex_t mutex;
sem_t sem;

// insert a task into the queue
// returns 0 if successful or 1 otherwise, 
int enqueue(task t) 
{
    t_queue *newLast = (t_queue *)calloc(1, sizeof(t_queue));
    newLast->t = t;
    if (last == NULL)
    {
        last = newLast;
    }
    else
    {
        last->next = (int *)newLast;
        last = newLast;
    }

    if (first == NULL)
    {
        first = last;
    }
    printf("e %d %d\n", (int)first, (int)last);
    return 0;
}

// remove a task from the queue
task dequeue() 
{
    // the work queue
    task worktodo;
    if (first == NULL)
    {
        
    }
    else
    {
        printf("d %d %d\n", (int)first, (int)last);
        worktodo = first->t;
        t_queue *oldFirst = first;
        first = (t_queue *)first->next;
        free(oldFirst);
        if (first == NULL)
        {
            last = NULL;
        }
    }
    return worktodo;
}

// the worker thread in the thread pool
void *worker(void *param)
{
    task worktodo;

    while (1)
    {
        sem_wait(&sem);
        // 1. dequeue // mutex lock
        pthread_mutex_lock(&mutex);
        worktodo = dequeue();
        pthread_mutex_unlock(&mutex);

        // 2. execute the task
        execute(worktodo.function, worktodo.data);
        printf("h\n");
        /* code */
    }
    
    // pthread_exit(0);
}

/**
 * Executes the task provided to the thread pool
 */
void execute(void (*somefunction)(void *p), void *p)
{
    (*somefunction)(p);
}

/**
 * Submits work to the pool.
 */
int pool_submit(void (*somefunction)(void *p), void *p)
{
    task worktodo;
    int result;
    worktodo.function = somefunction;
    worktodo.data = p;

    // mutex lock
    // 1. enqueue task
    pthread_mutex_lock(&mutex);
    result = enqueue(worktodo);
    pthread_mutex_unlock(&mutex);

    // use semaphore to signal waiting thread
    sem_post(&sem);

    // 2. 0 means success, 1 means failure


    return result;
}

// initialize the thread pool
void pool_init(void)
{
    // 1. create threads
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        pthread_create(&bee[i], NULL, worker, NULL);
    }

    // 2. establish mutexes and semaphores
    pthread_mutex_init(&mutex, NULL);
    sem_init(&sem, 0, 0);
}

// shutdown the thread pool
void pool_shutdown(void)
{
    // 1. cancel threads
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
        pthread_cancel(bee[i]);

    // 2. join threads
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
        pthread_join(bee[i], NULL);
}
