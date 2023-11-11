#include <stdlib.h>
#include <stdio.h>

int main()
{
		const char *path = malloc(sizeof(char) * 5);
		path = "PATH";
		path = getenv(path);
		if(!path)
			printf("can't find environmental varianle\n"), exit(1);
		printf("%s\n", path);
		return (0);
}
