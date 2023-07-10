#include "pthread.h"
#include "stdio.h"
#include "stdlib.h"
#include <math.h>

void *prime(void *arg); 

int main(int argc, char **argv)
{
    pthread_t tid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, &prime, argv[1]); 

    pthread_join(tid, NULL);    

    printf("\n");
}

void *prime(void *arg)
{
    int sqr_root, prime, number;
    int input = atoi((char *)arg);

    for (int number = 2; number <= input; number++)
    {
        sqr_root = (int)sqrt((double)number);

        prime = 1;

        for (int i = 2; i <= sqr_root; i++)
        {
            if (number % i == 0)
            {
                prime = 0;
            }
        }

        if (prime == 1)
        {
            printf("%d ", number);
        }
    }
}