#include "shell.h"

char *read_command()
{
	        char *command_line = NULL;
                int read;
                size_t size = 0;

		if (isatty(STDIN_FILENO) == 1)
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
int main(int argc  __attribute__((unused)) , char *argv[], char *env[] __attribute__((unused)))
{
		char *command_line;
		int error = 0;
	
		temp = malloc(sizeof(char) * strlen(argv[0]) + 1);
		strcpy(temp, argv[0]);
		do
		{
			command_line = read_command();
			if (!command_line)
				break;
			if (!set_argc(&argc, command_line))
				printf("%s: %s\n", temp, strerror(errno));
			if (!(argv = set_argv(argc, argv, command_line)))
				 printf("%s: %s\n", temp, strerror(errno));
			if (fork_exec(argv, env))
				printf("%s: %d: %s: notfound\n", temp, ++error, argv[0]);
		} while((command_line = read_command()));
		if (isatty(STDIN_FILENO))
                     printf("\n");
		return (0);
}
