#include "monty.h"

int execution(char *line, unsigned int line_num __attribute__((unused)), FILE **f __attribute__((unused)))
{
		char *cpy = _strdup(line);
		char *token = strtok(cpy, " \n\t");

		if (!token)
		{
			free(cpy);
			return (1);
		}

		free(cpy);
		return (0);
}
