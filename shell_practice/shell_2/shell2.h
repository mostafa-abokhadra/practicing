#ifndef __SHELL_2__
#define __SHELL_2__

#include "shell.h"

char *temp;

void _free2d(char **arr)
{
        int i;

        if (arr == NULL)
                return;
        for (i = 0; arr[i]; i++)
                free(arr[i]);
        free(arr);
}
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
int temp_alloc(char *str)
{
                temp = malloc(sizeof(char) * strlen(str) + 1);
                if (!temp)
                {
                         printf("%s: %s\n", str, strerror(errno));
                         free(temp);
                         return (0);
                }
		temp = strdup(str);
                return (1);
}

#endif /* __SHELL_2__ */
