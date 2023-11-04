#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

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

void func(char *command_line, char *argv[], int argc)
{
		char *token = malloc(sizeof(char));
		int i;
		argc = 0;

		token = strtok(command_line, " ");
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
                for(i = 0 ; i < argc; i++)
                {
                        printf("%s\n", argv[i]);
                }
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		for (i = 0; *argv[i]; i++)
		{
			printf("%s\n", *argv);
			argv++;
		}
}

int main(int argc , char *argv[] , char *env[] __attribute__((unused)))
{
		char *command_line = malloc(sizeof(char));
		char *token = malloc(sizeof(char));
		size_t command_line_size = 1;
		/* it will get resize as needed by getline */
		int characters_read = 0, i = 0;

		argc = 0;
		if (!command_line)
			printf(memerr), exit(0);
		printf("#cisfun$ ");
		characters_read = getline(&command_line, &command_line_size, stdin);
		if (characters_read == -1)
			printf("can't read from stdin\n"), exit(0);
		/* removing the newline from the command line */
		for (i = 0; command_line[i] != '\0'; i++)
		{
			if(!command_line[i + 1])
			{
				command_line[i] = '\0'; 
				break;
			}
		}
		characters_read--; /* subtracting the newline character */
		token = strtok(command_line, " ");
		while (token)
		{
			argc++;
			token = strtok(NULL, " ");
		}
		if (!argc)
			printf("argc = 0\n"), exit(0);
		argv = malloc(sizeof(char *) * (argc + 1));
		if (!argv)
			dprintf(STDERR_FILENO, memerr), exit(0);
		
		argv[0] = malloc(sizeof(char) * 5);
		argv[1] = malloc(sizeof(char) * 8);
		argv[2] = '\0';

		argv[0] = "yes";
		argv[1] = "ok";

		for (i = 0 ; i < argc ; i++)
		{
			printf("%s\n", argv[i]);
		}
		/*func(command_line, argv, argc);*/
		return (EXIT_SUCCESS);
}
