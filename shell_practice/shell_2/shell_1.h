#ifndef SHELL_1
#define SHELL_1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

extern char *environ[];

void _free2d(char **arr)
{
        int i;

        if (arr == NULL)
                return;
        for (i = 0; arr[i]; i++)
                free(arr[i]), arr[i] = NULL;
        free(arr), arr = NULL;
}

int fork_exec(char *tokenized[], char *argv[])
{
                pid_t pid;
                int status;

                pid = fork();
                if(pid == 0)
                {
                        if (execve(tokenized[0], tokenized, environ))
                         {
                                 perror(argv[0]);
                                  _free2d(tokenized);
                                  exit(0);
                         }
                }
                else
                {
                        waitpid(pid, &status, 0);
                        _free2d(tokenized);
                }
                return (WEXITSTATUS(status));
}
char **set_command(char *command_line)
{
                int argc = 0, i;
                char **tokenized = NULL;
                char *token = NULL;
                char *copy_command = NULL;

                if (!command_line)
                        return (NULL);
                copy_command = strdup(command_line);
                token = strtok(copy_command, " \n\t");
                if (!token)
                {
                        free(copy_command), copy_command = NULL;
                        free(command_line), command_line = NULL;
                        return (NULL);
                }
                for (; token; argc++, token = strtok(NULL, " \n\t"))
                {}
                free(copy_command), copy_command = NULL;
                tokenized = malloc(sizeof(char *) * (argc + 1));
                if (!tokenized)
                {
                        free(command_line), command_line = NULL;
                        return (NULL);
                }
                token = strtok(command_line, " \n\t");
                for (i = 0; token; i++, token = strtok(NULL, " \n\t"))
		{
                        tokenized[i] = strdup(token);
		}
                tokenized[i] = NULL;
                free(command_line), command_line = NULL;
                return (tokenized);
}
char *read_command()
{
                char *command_line = NULL;
                int read;
                size_t size = 0;

                if (isatty(STDIN_FILENO))
                printf("$ ");
                read = getline(&command_line, &size, stdin);
                if (read == -1)
                {
                        free(command_line);
                        return (NULL);
                }
                if (command_line[read - 1] == '\n' && read != 1)
                        command_line[read - 1] = '\0', read--;
                return (command_line);
}
#endif /* SHELL_1 */

