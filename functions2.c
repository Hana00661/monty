#include "monty.h"

/**
 * pint - a function that prints the value at the top of the stack
 * @stack: the list
 * @linenum: line of the command
 */

void pint(stack_t **stack, unsigned int linenum)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", linenum);
		error = 1;
		return;
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - a function that deletes the first node of the list
 * @stack: the list
 * @linenum: line of the command.
 */

void pop(stack_t **stack, unsigned int linenum)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", linenumb);
		error = 1;
		return;
	}
	*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(tmp);
}
