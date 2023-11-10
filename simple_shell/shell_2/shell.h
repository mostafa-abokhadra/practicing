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

int one_char (char *command_line)
{
                if (strcmp(command_line, "\n") == 0)
                        return (1);
        	return (0);
}
char *copycommand (char *command_line)
{
                char *copy_command = malloc(sizeof(char) * strlen(command_line) + 1);
                if (!copy_command)
                        return (NULL);
                strcpy(copy_command, command_line);
                return (copy_command);
}
char **set_argv(int argc, char *argv[], char *command_line)
{
                int i;
                char *token;
                char *copy_command = copycommand(command_line);
                argv = malloc(sizeof(char *) * argc + 1);
                if (!argv)
                {
                        MEMERR;
                        return (NULL);
                }
                token = strtok(copy_command, " ");
                for (i = 0; token; i++, token = strtok(NULL, " "))
                {
                        argv[i] = malloc(sizeof(char) * strlen(token) + 1);
                        if (!argv[i])
                        {
                                MEMERR;
                                return(NULL);
                        }
                        strcpy(argv[i], token);
                }
                argv[i] = NULL;
                return (argv);
}
int set_argc(int *argc, char *command_line)
{
                char *copy_command;
                char *token;

                *argc = 0;
                copy_command = copycommand(command_line);
                token = strtok(copy_command, " ");
                for (; token ; (*argc)++, token = strtok(NULL, " "))
                {}
                return (0);
}

#endif /* __SHELL__ */

