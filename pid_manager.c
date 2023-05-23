#include <stdio.h>

#define MIN_PID 300
#define MAX_PID 5000
#define BITMAP_SIZE (MAX_PID - MIN_PID)

int pid_bitmap[BITMAP_SIZE] = {0};

void release_pid(int pid);
int allocate_map(void);
int allocate_pid(void);

int main(void)
{
    allocate_map();

    printf("Allocate PID %d\n", allocate_pid());
    printf("Allocate PID %d\n", allocate_pid());
    printf("Allocate PID %d\n", allocate_pid());

    printf("Release PID 301\n");
    release_pid(301);
    printf("Allocate PID %d\n", allocate_pid());
    printf("Allocate PID %d\n", allocate_pid());
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
}

void release_pid(int pid)
{
    if (pid >= MIN_PID && pid <= MAX_PID)
    {
        pid_bitmap[pid - MIN_PID] = 0;
    }
}