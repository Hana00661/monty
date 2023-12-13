#include "monty.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}};

    while ((read = getline(&line, &len, stdin)) != -1)
    {
        line_number++;
        char *opcode = strtok(line, " \n");
        if (opcode == NULL || *opcode == '#')
            continue;

        int found = 0;
        for (int i = 0; instructions[i].opcode != NULL; i++)
        {
            if (strcmp(opcode, instructions[i].opcode) == 0)
            {
                instructions[i].f(&stack, line_number);
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    while (stack != NULL)
    {
        stack_t *tmp = stack;
        stack = stack->next;
        free(tmp);
    }

    return 0;
}