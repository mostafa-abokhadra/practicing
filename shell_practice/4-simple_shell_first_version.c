#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "fork.h"

#define memerr "cant't allocate memmory\n"

size_t _strlen(char *str)
{
		int counter = 0;

		if (str == NULL)
			return (0);
		while (*str)
		{
			counter++;
			str++;
		}
		return (counter);
}

void set_argv(char *command_line, char *argv[])
{
		char *command_line_copy = malloc(sizeof(char) * _strlen(command_line) + 1);
		char *token = malloc(sizeof(char));
		int i, argc = 0;

                if (!command_line_copy)
                        printf(memerr), exit(0);
		strcpy(command_line_copy, command_line);
		if (!token)
			printf(memerr), exit(0);
		token = strtok(command_line_copy, " ");
                while (token)
                {
                        argv[argc] = malloc(sizeof(char) * _strlen(token) + 1);
                        if(!argv[argc])
                                printf(memerr), exit(0);
                        for(i = 0; token[i] != '\0'; i++)
                        {
                                argv[argc][i] = token[i];
                        }
                        argv[argc][i] = '\0';
                        argc++;
			token = strtok(NULL, " ");
                }
                argv[argc] = NULL;
}
int set_argc(char *command_line)
{
                char *command_line_copy = malloc(sizeof(char) * _strlen(command_line) + 1);
		char *token;
		int argc = 0;

		if (!command_line_copy)
			printf(memerr), exit(0);
                strcpy(command_line_copy, command_line);
		token = malloc(sizeof(char));
		if (!token)
			printf(memerr), exit(0);
                token = strtok(command_line_copy, " ");
                while (token)
                {
                        argc++;
                        token = strtok(NULL, " ");
                }
		return argc;
}
char *set_command_line (char *command_line, int *characters_read)
{
		int i;
		/* removing the newline from the command line */
                for (i = 0; command_line[i] != '\0'; i++)
                {
                        if(!command_line[i + 1])
                        {
                                command_line[i] = '\0';
                                break;
                        }
                }
		/* subtracting the newline character */
		(*characters_read)--;
		return (command_line);
}
int main(int argc , char *argv[] , char *env[] __attribute__((unused)))
{
		char *command_line = malloc(sizeof(char));
		size_t command_line_size = 1;
		int characters_read = 0;

		start:
		argc = 0;
		if (!command_line)
			printf(memerr), exit(0);
		printf("#cisfun$ ");
		characters_read = getline(&command_line, &command_line_size, stdin);
		if (characters_read == -1)
			printf("can't read from stdin\n"), exit(0);
		command_line = set_command_line(command_line, &characters_read);
		if (strcmp(command_line,"^c") == 0)
			return (0);
		argc = set_argc(command_line);
		if (!argc)
			printf("argc = 0\n"), exit(0);
		argv = malloc(sizeof(char *) * (argc + 1));
		if (!argv)
			dprintf(STDERR_FILENO, memerr), exit(0);
		set_argv(command_line, argv);
		processing(argv);
		goto start;
		return (EXIT_SUCCESS);
}
