#include "shell.h"

int main(int argc , char *argv[], char *env[])
{
		char *command_line = malloc(sizeof(char));
		int read;
		size_t size = 1;

		temp = malloc(sizeof(char) * strlen(argv[0]) + 1);
		strcpy(temp, argv[0]);
		start:
		printf("#cisfun$ ");
		read = getline(&command_line, &size, stdin);
		if (read == -1) 
		{
			printf("%s: %s\n", temp, strerror(errno));
	       		goto start;
		}
		if(one_char(command_line) == 1)
                        goto start;
		if (command_line[read - 1] == '\n')
			command_line[read - 1] = '\0', read--;
		if (set_argc(&argc, command_line))
			goto start;
		if (!(argv = set_argv(argc, argv, command_line)))
			goto start;
		if (fork_exec(argv, env))
			printf("%s: %s\n", temp, strerror(errno));
		goto start;
		return (0);
}
