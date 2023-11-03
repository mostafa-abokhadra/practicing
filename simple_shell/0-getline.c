#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *str = malloc(sizeof(char) * 1);
	size_t size = 0;

	printf("$ ");
	getline(&str,&size,stdin);

	printf("$ %s", str);
	return (0);
}
