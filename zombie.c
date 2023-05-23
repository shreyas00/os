/*
 * Figure 3.30
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int value = 5;

int main()
{
	pid_t pid;

	pid = fork();
	
	if (pid == 0) { /* child process */
		return 0;
	}
	else if (pid > 0) { /* parent process */
		sleep(10);
		printf ("PARENT: value = %d\n",value); /* LINE A */
		return 0;
	}
}
