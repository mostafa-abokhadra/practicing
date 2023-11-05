#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)), char *env[] __attribute__((unused)))
{
		
		unsigned int i;
		struct stat st;
		if (argc < 2)
			dprintf(STDERR_FILENO, "file name is not specified \n"), exit(0);
		i = 1;
		while (argv[i])
		{
			if (stat(argv[i], &st) == 0)
				printf("FOUND\n");
			else
				printf("NOT FOUND\n");
			i++;
		}

		return (0);
		
}
