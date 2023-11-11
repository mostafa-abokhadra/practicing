#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char *env_sub_str(char *var, int read)
{
		int i;
		char *sub_env = malloc(sizeof(char) * read + 1);

		if (!sub_env)
			printf("memmory can't be allocated\n"), exit(1);
		for (i = 0; i < read; i++)
			sub_env[i] = var[i];
		sub_env[i] = '\0';
		return (sub_env);
}

char *solve(char *environ2[], char *env_var, int read)
{
		if (!(*(environ2)))
			return (NULL);
		if (strcmp(env_var, env_sub_str(*(environ2), read)) == 0)
			 return (*(environ2));
		environ2++;
		return (solve(environ2, env_var, read));
}
int main()
{
		char *env_var = malloc(sizeof(char) * 1);
		int read;
		size_t size = 1;
		char *returned;

		read = getline(&env_var, &size, stdin);
		if (read == -1)
			printf("getline can't read\n"), exit(1);
		if (env_var[read - 1] == '\n')
			env_var[read - 1] = '\0';
		read--;
		if (!(returned = solve(environ, env_var, read)))
			printf("can't find environmental variable\n"), exit(1);
		printf("%s\n", returned);
		return (0);
}
