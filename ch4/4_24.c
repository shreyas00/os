#include "pthread.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define TOTAL_POINTS 50000;

int points_inside;

void *get_rand(void *param);

int main(void)
{
    srand(1);
    
    pthread_t tid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, &get_rand, NULL);

    pthread_join(tid, NULL);

    double pi;
    pi = (4 * points_inside) / (double)TOTAL_POINTS;
    printf("Pi is %f\n", pi);
}

void * get_rand(void * param)
{
    int i = TOTAL_POINTS;
    double x,y;
    points_inside = 0;
    while (i-- > 0)
    {

        x = ((double)rand() / ((double)RAND_MAX / 2)) - 1.0f;
        y = ((double)rand() / ((double)RAND_MAX / 2)) - 1.0f;
        if (sqrt((x*x) + (y*y)) <= 1)
        {
            points_inside++;
        }
    }
    
}