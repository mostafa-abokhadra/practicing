#ifndef __SHELL__
#define __SHELL__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

#define MEMERR  printf("%s: %s\n", temp, strerror(errno))

char *temp;

int fork_exec(char *argv[], char *env[])
{
                pid_t pid;
                int status;
                int err = 0;

                pid = fork();
                if(pid == 0)
                         err = execve(argv[0], argv, env);
                else
                        wait(&status);
                return (err);
}
char **set_argv(int argc, char *argv[], char *command_line)
{
                int i;
                char *token;
                char *copy_command = strdup(command_line);

	        if (!copy_command)
			return (NULL);
                argv = malloc(sizeof(char *) * argc + 1);
                if (!argv)
                       return (NULL);
                token = strtok(copy_command, " \n\t");
                for (i = 0; token; i++, token = strtok(NULL, " \n\t"))
                {
                        argv[i] = malloc(sizeof(char) * strlen(token) + 1);
                        if (!argv[i])
                                return(NULL);
                        strcpy(argv[i], token);
                }
                argv[i] = NULL;
                return (argv);
}
int set_argc(int *argc, char *command_line)
{
                char *copy_command = strdup(command_line);
                char *token;
		
		if (!copy_command)
			return (0);
                *argc = 0;
                token = strtok(copy_command, " \n\t");
                for (; token ; (*argc)++, token = strtok(NULL, " \n\t"))
                {}
                return (1);
}

#endif /* __SHELL__ */

