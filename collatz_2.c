#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define SHM_SIZE_BYTES 4096

int main(void)
{
    int n = 35;
    printf("Enter number ");
    scanf("%d", &n);
    pid_t pid;

    int shm_fd;
    int *ptr;

    pid = fork();

    if (pid == 0)
    {
        /* create the shared memory segment */
        shm_fd = shm_open("COLLATZ", O_CREAT | O_RDWR, 0666);

        // Allocate size to shared memory
        ftruncate(shm_fd, SHM_SIZE_BYTES);

        // Addr, length, protection, flags, ID, offset
        ptr = mmap(0, SHM_SIZE_BYTES, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

        while (n != 1)
        {
            *(int *)ptr++ = n;
            if (n % 2 == 0)
            {
                n = n / 2;
            }
            else
            {
                n = (3 * n) + 1;
            }
            
        }
        *(int *)ptr++ = 1;
    }
    else if (pid > 0)
    {
        wait(NULL);
        shm_fd = shm_open("COLLATZ", O_RDONLY, 0666);
        ptr = mmap(0, SHM_SIZE_BYTES, PROT_READ, MAP_SHARED, shm_fd, 0);
        while (*ptr != 1)
        {
            printf("%d, ", *ptr++);
        }
        printf("1\n");
        
        shm_unlink("COLLATZ");
    }
    else
    {
        printf("Fork failed");
    }
    
}