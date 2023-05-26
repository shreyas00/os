/**
 * Simple shell interface program.
 *
 * Operating System Concepts - Tenth Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 80 /* 80 chars per line, per command */

int main(void)
{
    char *args[MAX_LINE / 2 + 1]; /* command line (of 80) has max of 40 arguments */
    int should_run = 1;
    char line[MAX_LINE];
    char token[MAX_LINE*2]; // Null separated character array used as tokens

    int idx = 0;    // Line character index
    int argsIdx = 0; // args Array Index
    int spaceFound = 0;
    int background;

    while (should_run)
    {
        printf("osh>");
        fflush(stdout);

        // Read line array from stdin
        fgets(line, MAX_LINE, stdin);

        // TODO Exit

        if(line[0] == '!' && line[1] == '!')
        {

        }
        else
        {
            // Clear args and tokens
            memset(&args, 0, sizeof(args));
            memset(&token, 0, sizeof(token));

            // Prepare to tokenize
            idx = 0;
            argsIdx = 0;
            // First arg points to start of token
            args[0] = &token[0];
            while (line[idx] != 0 && line[idx] != '\n')
            {
                if (line[idx] == ' ') // Ignore all spaces
                {
                    spaceFound = 1;
                }
                else
                {
                    if (spaceFound == 1)
                    {
                        argsIdx++;                   // Time for next argument
                        token[idx - 1] = '\0';       // Next token starts after NULL
                        args[argsIdx] = &token[idx]; // Next argument starts from next character
                        spaceFound = 0;
                    }
                    token[idx] = line[idx];
                }
                idx++;
            }
            token[idx] = '\0';
        }
        

        

        // Find whether process to be run in bg
        background = 0;
        if (token[idx - 1] == '&')
        {
            background = 1;
            token[idx - 1] = '\0';
        }        

        pid_t pid;
        pid = fork();

        if (pid > 0)
        {
            if (background == 0)
            {
                wait(NULL);
            }
            fflush(stdout);
        }
        else
        {
            execvp(args[0], args);
        }
    }

    return 0;
}
