#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    int n;
    printf("Enter number ");
    scanf("%d", &n);
    pid_t pid;

    pid = fork();

    if (pid == 0)
    {
        while (n != 1)
        {
            printf("%d, ", n);
            if (n % 2 == 0)
            {
                n = n / 2;
            }
            else
            {
                n = (3 * n) + 1;
            }
            
        }
        printf("1\n");
    }
    else if (pid > 0)
    {
        wait(NULL);
    }
    else
    {
        printf("Fork failed");
    }
    
}