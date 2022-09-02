#include "monty.h"

/**
 *
 *
 *
 */

void op_swap(stack_t **stack, unsigned int line_number)
{
	int count = 0, change = 0;
	stack_t *temporal = *stack;

	while (temporal)
	{
		count++;
		temporal = temporal->next;
	}

	if (count < 2)
	{
		if (*stack == NULL || (*stack)->next == NULL)
		{
			fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	change = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = change;
}
