#include "monty.h"

/**
 * new_Node - a funtion that create new node
 * @n: is an integer data.
 * Return: a new node
*/

stack_t *new_Node(int n)
{
    stack_t *new = NULL;

    new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        dprintf(STDERR_FILENO, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new->n = n;
    new->next = NULL;
    new->prev = NULL;

    return (new);
}

/**
 * push - a function that push an item into stack.
 * @stack: is a parameter.
 * @line_number: data.
 * Return: void.
 */

void push(stack_t **stack, unsigned int line_number)
{
    char *token;
    int num;

    token = strtok(NULL, " \n");
    if (token == NULL)
    {
        dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    num = atoi(token);
    if (num == 0 && *token != '0')
    {
        dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (*stack == NULL)
        *stack = new_Node(num);
    else
    {
        stack_t *new = new_Node(num);
        new->next = *stack;
        (*stack)->prev = new;
        *stack = new;
    }
}
/**
 * pall - a function that print all elements of the stack
 * @stack: is a parameter
 * @n: is value
 * Return: void.
*/
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
