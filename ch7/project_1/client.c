/**
 * Example client program that uses thread pool.
 */

#include <stdio.h>
#include <unistd.h>
#include "threadpool.h"

struct data
{
    int a;
    int b;
};

void add(void *param)
{
    struct data *temp;
    temp = (struct data*)param;

    printf("I add two values %d and %d result = %d\n",temp->a, temp->b, temp->a + temp->b);
}

int main(void)
{
    // create some work to do
    struct data work[3];

    // initialize the thread pool
    pool_init();

    // submit the work to the queue
    work[0].a = 5;
    work[0].b = 10;
    pool_submit(&add,&work[0]);
    work[1].a = 20;
    work[1].b = 10;
    pool_submit(&add,&work[1]);
    work[2].a = 30;
    work[2].b = 10;
    pool_submit(&add,&work[2]);
    sleep(1);
    pool_submit(&add,&work[2]);
    pool_submit(&add,&work[2]);

    // may be helpful 

    pool_shutdown();

    return 0;
}
