#include "monty.h"

int error = 0;
/**
 *main - the Entery Point
 *@argv: tab of arguments
 *@argc: number of arguments
 *Return: EXIT_FAILURE or EXIT_SUCCESS
 */

int main(int argc, char **argv)
{
	FILE *ptr;
	char *line = NULL, *token = NULL;
	size_t size = 0;
	stack_t *stack = NULL;
	unsigned int linenum = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ptr = fopen(argv[1], "r");
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &size, ptr) != -1 && error != 1)
	{
		linenum++;
		token = strtok(line, "\n\t ");
		if (token == NULL || strncmp(token, "#", 1) == 0)
			continue;
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\n\t ");
			
		}
		else
			op_funcs(token, &stack, linenum);
	}
	free_all(stack, line, ptr);
	if (error == 1)
		exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

