#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define SHM_SIZE_BYTES 4096
#define READ_END 0
#define WRITE_END 1

int pc[2]; // Parent to child
int cp[2]; // Child to parent

int main(void)
{
    
    if (pipe(pc) == -1)
    {
        printf("Pipe error");
    }
    if (pipe(cp) == -1)
    {
        printf("Pipe error");
    }

    pid_t pid;

    pid = fork();

    if (pid == 0)
    {
        close(cp[READ_END]);
        close(pc[WRITE_END]);

        char msg[100], send[100];
        read(pc[READ_END], &msg, 100);

        int idx = 0;
        while(msg[idx] != 0)
        {
            if(islower(msg[idx]))
            {
                send[idx] = toupper(msg[idx]);
            }
            else if (isupper(msg[idx]))
            {
                send[idx] = tolower(msg[idx]);

            }
            else
            {
                send[idx] = msg[idx];
            }
            
            idx++;
        }
        write(cp[WRITE_END], &send, 100);

        close(pc[READ_END]);
        close(cp[WRITE_END]);
    }
    else
    {
        char msg[100] = "It's me. Hi!";
        write(pc[WRITE_END], &msg, 100);
        close(pc[WRITE_END]);
        close(pc[READ_END]);
        close(cp[WRITE_END]);

        wait(NULL);

        read(cp[READ_END], &msg, 100);
        printf("%s\n", msg);
        close(cp[READ_END]);
    }
    
}