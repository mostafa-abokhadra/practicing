#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#include "monty.h"

void pall(stack_t *head)
{
	stack_t *t = head;
	
	for (; t != NULL ; t = t->next)
		printf("%d\n", t->n);
}
stack_t *push(stack_t *head, char *str)
{
		stack_t *new_node = malloc(sizeof(stack_t));
		int num;

		if (!new_node)
			printf("Error: malloc failed\n"), exit(EXIT_FAILURE);
		num = atoi(str);
		new_node->n = num;
		new_node->next = head;
		new_node->prev = NULL;
		head = new_node;
		return (head);
}

stack_t *decide(char *str, stack_t *head)
{
	char *token = NULL;
	char *str_copy = malloc(sizeof(char) * strlen(str) + 1);

	if (!str_copy)
		printf("Error: malloc failed\n"), exit(EXIT_FAILURE);
	strcpy(str_copy, str);
	token = strtok(str_copy, " \n$\0");
	while(token != NULL)
	{
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " \n$\0");
			head = push(head,token);
		}
		else if (strcmp(token, "pall") == 0)
			pall(head);
		token = strtok(NULL, " \n$\0");
	}
	free(str_copy);
	return (head);
}
int main(int argc, char **argv)
{
		stack_t *head = NULL;
		FILE *fily;
		char *buff = malloc(sizeof(char));
		int size = 1024;

		if (argc == 1)
			printf("USAGE: monty file\n"), exit(EXIT_FAILURE);
		fily = fopen(argv[1], "r");
		if (fily == NULL)
			printf("Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);

		while(fgets(buff, size, fily) != NULL)
		{
			head = decide(buff, head);
		
		}
		
		return (0);
}
