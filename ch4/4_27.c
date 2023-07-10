#include "pthread.h"
#include "stdio.h"
#include "stdlib.h"

int *fib;

void *gen_fib(void *param);

int main(int argc, char **argv)
{
    int fib_sz = atoi(argv[1]);

    fib = malloc(fib_sz * sizeof(int));

    pthread_t tid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, &gen_fib, argv[1]);

    pthread_join(tid, NULL);

    for(int i = 0; i < fib_sz; i++)
    {
        printf("%d ", fib[i]);
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
    }
    else if(fib_sz == 2)
    {
        fib[0] = 0;
        fib[1] = 1;
    }
    else
    {
        fib[0] = 0;
        fib[1] = 1;
        for (int i = 2;  i < fib_sz; i++)
        {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
    }
}