#include "monty.h"

/**
 *
 */

void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	stack_t *current = *stack;
	int count = 0;

	while (current)
	{
		count++;
		current = current->next;
	}

	if (count < 2)
	{
		if (tmp == NULL || (*stack)->next == NULL)
		{
			fprintf(stderr, "L%d: can't add\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	(tmp->next)->n = tmp->n + (tmp->next)->n;
	op_pop(stack, line_number);
}
