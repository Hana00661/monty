#include "monty.h"

/**
 * sub - opcode subtracts the top element from the second top element.
 * @stack: the parameter list
 * @linenum: the number of the node
 * Return: void.
 */

void sub(stack_t **stack, unsigned int linenum)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", linenum);
		error = 1;
		return;
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, linenum);
}

/**
 * op_div - opcode that divides the second element by the top element
 * @stack: the list
 * @linenum: number of lines of the command
 * Return: void.
 */

void op_div(stack_t **stack, unsigned int linenum)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", linenum);
		error = 1;
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", linenum);
		error = 1;
		return;
	}
	(*stack)->next->n /= (*stack)->n;
	pop(stack, linenum);
}

/**
 * mul - opcode that multiplies the second element with the top element
 * @stack: our list
 * @linenum: number of line of the command
 * Return: void.
 */

void mul(stack_t **stack, unsigned int linenum)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", linenum);
		error = 1;
		return;
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, linenum);
}

/**
 * mod - opcode that computes the rest of the division
 *		of the second element by the top element.
 * @stack: the parameter list
 * @linenum: number of lines of the command
 * Return: void
 */

void mod(stack_t **stack, unsigned int linenum)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", linenum);
		error = 1;
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", linenum);
		error = 1;
		return;
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, linenum);
}
