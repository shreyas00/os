// Compile with -fopenmp -lm
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define TOTAL_POINTS 60000

int points_inside;

int main(void)
{
    srand(1);

    int i;
    double x, y;
    points_inside = 0;

#pragma omp parallel for
    for (i = 0; i < TOTAL_POINTS; i++)
    {

        x = ((double)rand() / ((double)RAND_MAX / 2)) - 1.0f;
        y = ((double)rand() / ((double)RAND_MAX / 2)) - 1.0f;
        if (sqrt((x * x) + (y * y)) <= 1)
        {
            points_inside++;
        }
    }

    double pi;
    pi = (4 * points_inside) / (double)TOTAL_POINTS;
    printf("Pi is %f\n", pi);
}
