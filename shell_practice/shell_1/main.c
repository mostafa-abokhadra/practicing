#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

#define MEMERR printf("%s: %s\n",temp, strerror(errno))
#define IOERR printf("%s: %s\n",temp, strerror(errno))
#define NOT_EXIST printf("%s: %s\n", temp, strerror(errno))

char *name;

int fork_exec(char *argv[], char *env[])
{
		pid_t pid;
		int status;

		pid = fork();
		if (pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				NOT_EXIST;
		}
		else
			wait(&status);
		return (1);
}
int _strlen(char *str)
{
		int counter = 0;

		if (!str)
			return (0);
		for (; *str; counter++, str++)
		{}
		return (counter);
}
int check_command(char *command_line, int read)
{
		int counter = 0;
		char *copy_command = malloc(sizeof(char) * read + 1);
		char *token = malloc(sizeof(char));

		if (!copy_command)
			MEMERR;
		strcpy(copy_command, command_line);
		token = strtok(copy_command, " ");
		for(;token; token = strtok(NULL, " "))
			counter++;
		if (counter > 1)
			return (0);
		return (1);
}
char **set_args(int *argc, char *argv[], char *command_line, int read)
{
		*argc = 1;
		argv = malloc(sizeof(char *) * 2);
		if (!argv)
			MEMERR;
		argv[0] = malloc(sizeof(char) * read + 1);
		if (!argv[0])
			MEMERR;
		strcpy(argv[0], command_line);
		argv[1] = NULL;
		return (argv);
} 
int main (int argc , char *argv[], char *env[])
{
		int read = 0;
		char *command_line = malloc(sizeof(char));
		size_t size = 1;
		name = malloc(sizeof(char) * _strlen(argv[0]) + 1);


		strcpy(name, argv[0]);
		start:
		printf("#cisfun$ ");
		read = getline(&command_line, &size, stdin);
		if (read == -1)
			IOERR;
		if (strcmp(command_line, "\n") == 0)
			goto start;
		if (command_line[read - 1] == '\n')
                       command_line[read - 1] = '\0';
		read--;
		if (!check_command(command_line, read))
		{
			NOT_EXIST;
			goto start;
		}
		argv = set_args(&argc, argv, command_line, read);
		fork_exec(argv, env);
		goto start;
		return (0);
}
