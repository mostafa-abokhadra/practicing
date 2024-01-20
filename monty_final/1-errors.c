#include "monty.h"

/**
 *
 *
 *
 *
 *
 */
void less_than_two()
{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
}
/**
 *
 *
 *
 *
 */
void not_found(char *file_name)
{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
}
