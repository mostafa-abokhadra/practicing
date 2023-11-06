#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)), char **env)
{
		printf("environ address = %p\n", *(environ));
		printf("env address	= %p\n", *(env));
		return (0);
}
