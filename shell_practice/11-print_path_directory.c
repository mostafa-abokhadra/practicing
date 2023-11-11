#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

char *path_pointer(char *env)
{
		int i;
		char *sub_env = malloc(sizeof(char) * 5);

		for (i = 0 ; i < 4; i++)
			sub_env[i] = env[i];
		sub_env[i] = '\0';
		if (strcmp(sub_env, "PATH") == 0)
			return(*(environ));
		environ++;
		return (path_pointer(*(environ)));
}
int main()
{
		int i;
		char *path = path_pointer(*(environ));
		char *token;

		for (i = 0;i < 5; i++)
			path++;
		token = strtok(path, ":");
		while (token)
		{
			printf("%s\n", token);
			token = strtok(NULL, ":");
		}
		return (0);
}
