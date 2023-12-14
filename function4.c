#include "monty.h"

/**
 * pchar - opcode that prints the char at the top of the stack.
 * @stack: the parameter list
 * @linenum: number of lines of the command.
 * Return: void
 */

void pchar(stack_t **stack, unsigned int linenum)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", linenum);
		error = 1;
		return;
	}
	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", linenum);
		error = 1;
		return;
	}
	putchar((*stack)->n);
	putchar('\n');
}

/**
 * pstr - an opcode starting at the top of the stack that print a string
 * @stack: the parameter list
 * @linenum: number of lines of the command.
 * Return: void.
 */

void pstr(stack_t **stack, unsigned int linenum)
{
	stack_t *tmp = *stack;
	(void)linenum;

	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}
	while (tmp && tmp->n != 0 && tmp->n < 127 && tmp->n > 0)
	{
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * rotl - opcode that rotates the stack to the top
 * @stack: the parameter list
 * @linenum: the number of the node
 * Return: void.
 */

void rotl(stack_t **stack, unsigned int linenum)
{
	stack_t *tmp = *stack;
	stack_t *last;

	(void)linenum;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	last = *stack;

	while (last->next)
	{
		last = last->next;
	}
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
}

/**
 * rotr - an opcode that rotates the stack to the bottom
 * @stack: the list
 * @linenum: the number of nodes.
 * Return: void.
 */

void rotr(stack_t **stack, unsigned int linenum)
{
	stack_t *tmp = *stack;

	(void)linenum;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->prev->next = NULL;
	(*stack)->prev = tmp;
	tmp->next = *stack;
	tmp->prev = NULL;
	*stack = tmp;
}
