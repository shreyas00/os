#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define READ_END 0
#define WRITE_END 1

int fd[2];

int main(int argc, char **argv)
{
    char *src = argv[1];
    char *dst = argv[2];

    if (pipe(fd) == -1)
    {
        printf("Error");
    }

    // Open file
    FILE *srcFile = fopen(src, "r");
    // Go to end
    fseek(srcFile, 0, SEEK_END);
    // Tell end position
    long int numChars = ftell(srcFile);
    // Go to start
    fseek(srcFile, 0, 0);

    pid_t pid = fork();

    if (pid == 0)
    {
        close(fd[WRITE_END]);
        
        // Open file
        FILE *dstFile = fopen(dst, "w");

        // Create buffer to hold file content
        int *buffer = malloc(numChars * sizeof(char));
        // Read from pipe to buffer
        read(fd[READ_END], buffer, numChars);
        // Write from buffer to filestream
        fwrite(buffer, sizeof(char), numChars, dstFile);
        // Close file
        fclose(dstFile);
        // Free buffer
        free(buffer);

        close(fd[READ_END]);
    }
    else
    {
        close(fd[READ_END]);
        
        // Create buffer to hold file content
        int *buffer = malloc(numChars * sizeof(char));
        // Read from filestream to buffer
        fread(buffer, sizeof(char), numChars, srcFile);
        // Write from buffer to pipe
        write(fd[WRITE_END], buffer, numChars);
        // Close src file
        fclose(srcFile);
        // Free buffer
        free(buffer);
        
        close(fd[WRITE_END]);

        wait(NULL);
    }
    return 0;
}