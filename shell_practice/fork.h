#ifndef __HEADER__
#define __HEADER__

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

void processing(char *argv[])
{
		int status;
		pid_t my_pid;

		my_pid = fork();
		if (my_pid == -1)
			dprintf(STDERR_FILENO, "can't fork\n");
		if (my_pid == 0)
			execve(argv[0], argv, NULL);
		else
			wait(&status);
}

#endif /* __HEADER__ */
