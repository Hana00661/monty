#include "monty.h"
/**
 * push - a function that push an item into stack.
 * @token: number to add in the node
 * @stack: is a parameter.
 * @linenum: line of the command.
 * Return: void.
 */

void push(char *token, stack_t **stack, unsigned int linenum)
{
	int i;
	stack_t *new = NULL;

	if (token == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", linenum);
		error = 1;
		return;
	}
	for (i = 0; token[i] != '\0'; i++)
	{
		if (token[i] == '-')
			i++;
		if (isdigit(token[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", linenum);
			error = 1;
			return;
		}
	}
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		perror("Error: malloc failed\n");
		error = 1;
		return;
	}
	new->n = atoi(token);
	new->prev = NULL;
	new->next = NULL;

	if (*stack)
	{
		(*stack)->prev = new;
		new->next = *stack;
	}
	*stack = new;
}

/**
 * pall - a function that print all elements of the stack
 * @stack: is a parameter
 * @linenum: line of the command
 * Return: void.
*/

void pall(stack_t **stack, unsigned int linenum)
{
	stack_t *temp = *stack;
	(void)linenum;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * free_all - free all and close the file
 * @stack: the list to free
 * @line: the line of getline to free
 * @ptr: the file to close
 * Return: void
 */

void free_all(stack_t *stack, char *line, FILE *ptr)
{
	stack_t *tmp = stack;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	free(line);
	fclose(ptr);
}

/**
 *op_funcs - give the good function
 *@line: the line read
 *@stack: a prameter
 *@linenum: the number of the line
 *Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int op_funcs(char *line, stack_t **stack, unsigned int linenum)
{
	instruction_t func[] = {
		{"pall", pall},
		{"pint", _pint},
		{"pop", _pop},
		{NULL, NULL},

		};
	int i;

	for (i = 0; func[i].opcode != NULL; i++)
	{
		if (strcmp(line, func[i].opcode) == 0)
		{
			func[i].f(stack, linenum);
			return (EXIT_SUCCESS);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", linenum, line);
	error = 1;
	return (EXIT_FAILURE);
}
