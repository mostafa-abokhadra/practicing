#include <stdio.h>
#include <unistd.h>

int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)), char *env[])
{
		while (*(env))
		{
			printf("%s\n", *(env));
			env++;
		}
		return (0);
}
