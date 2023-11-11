#ifndef __SHELL__
#define __SHELL__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include "shell2.h"

extern char *environ[];

int fork_exec(char *argv[])
{
                pid_t pid;
                int status;
            
                pid = fork();
                if(pid == 0)
		{
                        if (execve(argv[0], argv, environ))
			 {
				 printf("%s: %s\n", temp, strerror(errno));;
				 _free2d(argv);
				 exit(127);
			 }
		}
                else
		{
                        waitpid(pid, &status, 0);
			_free2d(argv);
		}
                return (WEXITSTATUS(status));
}
int set_argc(int *argc, char *command_line)
{
                char *copy_command = strdup(command_line);
                char *token = NULL;

                *argc = 0;
                token = strtok(copy_command, " \n\t");
                if (!token)
                {
                        free(command_line);
                        free(copy_command);
                        return (0);
                }
                for (; token ; (*argc)++, token = strtok(NULL, " \n\t"))
                {}
                free(copy_command);
                return (1);
}
char **set_argv(int *argc, char *argv[], char *command_line)
{
                int i;
                char *token = NULL;
                char *copy_command = NULL;

		if (!command_line)
			return (NULL);
		copy_command = strdup(command_line);
		token = strtok(copy_command, " \n\t");
		if (!token)
                {
                        free(command_line);
                        free(copy_command);
                        return (NULL);
                }
		if(!set_argc(argc, command_line))
			return (NULL);
                argv = malloc(sizeof(char *) * (*argc) + 1);
                if (!argv)
		{
		       free(command_line);
                       return (NULL);
		}
                for (i = 0; token; i++, token = strtok(NULL, " \n\t"))
                        argv[i] = strdup(token);
                argv[i] = NULL;
		free(command_line);
                return (argv);
}
#endif /* __SHELL__ */

