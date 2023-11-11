#include "shell_1.h"

int main(int argc __attribute__((unused)), char *argv[])
{
		int out = 0;
		char *command_line = NULL;
		char **tokenized = NULL;
	
		while(1)
		{
			command_line = read_command();
			if (!command_line)
			{
				if (isatty(STDIN_FILENO))
					printf("\n");
				return (out);
			}
			if(!(tokenized = set_command(command_line)))
				continue;
			out = fork_exec(tokenized, argv);
		}
		return (0);
}
