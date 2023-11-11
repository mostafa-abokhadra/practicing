#include "shell.h"
#include "shell2.h"

int main(int argc __attribute__((unused)), char *argv[])
{
		char *command_line = NULL;

		while(1)
		{
			command_line = read_command();
			if (!command_line)
			{
		               if (isatty(STDIN_FILENO))
                	     		printf("\n");
			       free(command_line);
			       return (0);
			}
			if (!(argv = set_argv(&argc, argv, command_line)))
				 printf("%s: %s\n", temp, strerror(errno));
			fork_exec(argv);
		}
		free(temp);
		return (0);
}
