#include "pthread.h"
#include "stdio.h"
#include "stdlib.h"
#include "semaphore.h"

int *fib;
sem_t full;

void *gen_fib(void *param);

int main(int argc, char **argv)
{
    int fib_sz = atoi(argv[1]);

    fib = malloc(fib_sz * sizeof(int));

    // Initialize unnamed semaphore. 0 means only children threads can access.
    sem_init(&full, 0, 0); // Initialize full to 0 which means wait for child to post.

    pthread_t tid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, &gen_fib, argv[1]);

    // Don't wait for child to complete
    // pthread_join(tid, NULL);
    int i = 0;
    while(i < fib_sz)
    {
        sem_wait(&full);

        printf("%d ", fib[i]);
        i++;
    }
    printf("\n");

    free(fib);
}

void *gen_fib(void *param)
{
    int fib_sz = atoi((char *)param);
    if (fib_sz == 0)
    {
        
    }
    else if (fib_sz == 1)
    {
        fib[0] = 0;
        sem_post(&full);
    }
    else if(fib_sz == 2)
    {
        fib[0] = 0;
        sem_post(&full);
        fib[1] = 1;
        sem_post(&full);
    }
    else
    {
        fib[0] = 0;
        sem_post(&full);
        fib[1] = 1;
        sem_post(&full);
        for (int i = 2;  i < fib_sz; i++)
        {
            fib[i] = fib[i - 1] + fib[i - 2];
            sem_post(&full);
        }
    }
}