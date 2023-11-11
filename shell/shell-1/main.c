#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

char *name;

char *copy (char *command)
{
		 char *copy_command = malloc(sizeof(char) * strlen(command) + 1);
		 if (!copy_command)
			 return (NULL);
		 strcpy(copy_command, command);
		 return (copy_command);
}
int set_argv(char *command, char **arr, int argc)
{
		 int i;
		 char *comm = copy(command);
                 char *token;
		 arr = malloc(sizeof(char *) * argc + 1);
		
		 if (!comm)
		 	return (0);
		 if (!arr)
			return (0);
		 token = strtok(comm, " ");
		 for (i = 0; token ; i++, token = strtok(NULL, " "))
		 {
			 arr[i] = malloc(sizeof(char) * strlen(token) + 1);
			 if (!arr[i])
				 return (0);
			 strcpy(arr[i], token);
		 }
		 arr[i] = NULL;
		 while (*(arr))
		 {
			 printf("func: %s\n", *(arr));
			 arr++;
		 }
		 return (1);
}
int set_argc (int *argc, char *command)
{
		char *comm = copy(command);
		char *token;
		
		*argc = 0;
		if (!comm)
			return (0);
		token = strtok(comm, " ");
		for (; token; (*argc)++, token = strtok(NULL, " "))
		{}
		return (1);
}
int main(int argc __attribute__((unused)), char **argv, char *env[] __attribute__((unused)))
{
		int /*error_count = 0,*/ read = 0;
		char *command_line = NULL;
		size_t size = 32;
		
		name = malloc(sizeof(char) * strlen(argv[0] + 1));
		strcpy(name, argv[0]);
		argv = NULL;
		printf("#cisfun$ ");
		read = getline(&command_line, &size, stdin);
		if (read == -1)
			printf("%s: %s\n", name, strerror(errno));
		if (!set_argc(&argc, command_line))
			printf("%s: %s\n", name, strerror(errno));
		set_argv(command_line, argv, argc);
		 while (*(argv))
                 {
			 printf("ook\n\n");
                         printf("main: %s\n", *(argv));
                         argv++;
                 }
		return (0);
}
