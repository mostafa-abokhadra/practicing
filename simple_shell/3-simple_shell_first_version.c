#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

char *convert_to_bash(char *argv[])
{
                int i = 1, j = 0, count = 0;
                char *bash_command = NULL;

                for(i; argv[i] != NULL; i++)
                {
                    for(j = 0; argv[i][j] != '\0'; j++)
                    {
                        count++;
                    }
                    if(argv[i+1] != NULL)
                        count++;
                }
                bash_command = malloc(sizeof(char) * (count + 1));
                count = 0;
                for(i = 1; argv[i] != NULL; i++)
                {
                    for (j = 0; argv[i][j] != '\0'; j++)
                        bash_command[count++] = argv[i][j];
                        bash_command[count++] = ' ';
                }
                bash_command[count]='\0';
                return (bash_command);
}

int main(int argc __attribute__((unused)), char *argv[], char *envp[] __attribute__((unused)))
{
		int fd;
                pid_t my_pid;
                char *bash_command = convert_to_bash(argv);
                fd = open("command.sh", O_WRONLY | O_CREAT,0555);
                dprintf(fd, "#!/bin/bash\n%s", bash_command);
                close(fd);
                execve("./command.sh", argv, NULL);
		/*
		start:
		my_pid = fork();
		if (my_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if(my_pid == 0)
		{
			if (execve(argv[1], argv, NULL) == -1)
			{
				perror("Error2: ");
				return (1);
			}
			printf("%d child done\n", i);
		}
		else
	       	{
			wait(&status);
			while(i < 5)
			{
				i++;
				goto start;
			}
		}
		*/
		return (0);
}
