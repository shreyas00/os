#include "pthread.h"
#include "stdio.h"
#include "stdlib.h"

void *max(void * integer_array);
void *min(void * integer_array);
void *avg(void * integer_array);

int num_integers;
int max_integer;
int min_integer;
int avg_integer;


int main(int argc, char **argv)
{
    num_integers = argc - 1;
    int *integer_array = malloc(num_integers * sizeof(int));
    // Convert to integer
    for (int i = 0; i < num_integers; i++)
    {
        integer_array[i] = atoi(argv[i + 1]);
    }

    pthread_t max_tid, min_tid, avg_tid;
    pthread_attr_t attr;

    // Initialize default thread attributes
    pthread_attr_init(&attr);

    // Create thread
    pthread_create(&max_tid, &attr, max, integer_array);
    // Create thread
    pthread_create(&min_tid, &attr, min, integer_array);
    // Create thread
    pthread_create(&avg_tid, &attr, avg, integer_array);

    // Join
    pthread_join(max_tid, NULL);
    // Join
    pthread_join(min_tid, NULL);
    // Join
    pthread_join(avg_tid, NULL);

    printf("The max number is %d\n", max_integer);
    printf("The min number is %d\n", min_integer);
    printf("The avg number is %d\n", avg_integer);
}

void *max(void *integer_array)
{
    int *numL = (int *)integer_array;
    max_integer = numL[0];
    for (int i = 0; i < num_integers; i++)
    {
        if (numL[i] > max_integer)
        {
            max_integer = numL[i];
        }
    }
}

void *min(void *integer_array)
{
    int *numL = (int *)integer_array;
    min_integer = numL[0];
    for (int i = 0; i < num_integers; i++)
    {
        if (numL[i] < min_integer)
        {
            min_integer = numL[i];
        }
    }
}

void *avg(void *integer_array)
{
    int *numL = (int *)integer_array;
    avg_integer = 0;
    for (int i = 0; i < num_integers; i++)
    {
        avg_integer += numL[i];
    }
    avg_integer = avg_integer / num_integers;
}