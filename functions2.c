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
		fprintf(stderr, "L%d: can't pop an empty stack\n", linenum);
		error = 1;
		return;
	}
	*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(tmp);
}

/**
 * swap - a function that swaps betwwen the top two elements.
 * @stack: our parameter.
 * @linenum: the number of nodes that added.
 * Return: void.
 */

void swap(stack_t **stack, unsigned int linenum)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", linenum);
		error = 1;
		return;
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * add - function oparation that adds the top two elements of the stack.
 * @stack: our focus paramter.
 * @linenum: number of the lines of the command.
 * Return: void.
 */

void add(stack_t **stack, unsigned int linenum)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", linenum);
		error = 1;
		return;
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, linenum);
}

/**
 * nop - The opcode doesn’t do anything.
 * @stack: our focus paramter.
 * @linenum: number of lines of the command
 * Return: void.
 */

void nop(stack_t **stack, unsigned int linenum)
{
	(void)stack;
	(void)linenum;
}
