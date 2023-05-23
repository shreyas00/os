#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

// #define IPC_SHM
#define IPC_PIPE
#define READ_END 0
#define WRITE_END 1
#define SHM_SIZE_BYTES 4096


struct timeval tv1, tv2; 
struct timezone tz;
int status, fd[2];

int main(void)
{
	
	pid_t pid;

	if (pipe(fd) == -1)
	{
		printf("PIPE ERROR");
	}

	pid = fork();

	if(pid == 0)
	{
#ifdef IPC_SHM
		int shm_fd;
		void *ptr;

		/* create the shared memory segment */
		shm_fd = shm_open("TIME", O_CREAT | O_RDWR, 0666);

		// Allocate size to shared memory
		ftruncate(shm_fd, SHM_SIZE_BYTES);

		// Addr, length, protection, flags, ID, offset
		ptr = mmap(0, SHM_SIZE_BYTES, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

		status = gettimeofday((struct timeval *)ptr, &tz);
#endif
#ifdef IPC_PIPE
		close(fd[READ_END]);

		status = gettimeofday(&tv1, &tz);
		write(fd[WRITE_END], &tv1, sizeof(tv1));

		close(fd[WRITE_END]);
#endif

		execlp("ls", "ls", NULL);
	}
	else
	{
		wait(NULL);
#ifdef IPC_SHM
		int shm_fd;
		void *ptr;

		/* create the shared memory segment */
		shm_fd = shm_open("TIME", O_RDONLY, 0666);

		ptr = mmap(0, SHM_SIZE_BYTES, PROT_READ, MAP_SHARED, shm_fd, 0);

		memcpy(&tv1, ptr, sizeof(tv1));

		shm_unlink("TIME");
#endif
#ifdef IPC_PIPE
		close(fd[WRITE_END]);

		read(fd[READ_END], &tv1, sizeof(tv1));

		close(fd[READ_END]);
#endif

		status = gettimeofday(&tv2, &tz);

		printf("Time %.3f\n", (double)(tv2.tv_usec - tv1.tv_usec)/1e6);
	}
	return 0;
}