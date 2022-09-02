#include "monty.h"

/**
 *
 */

void op_pop(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		dprintf(2, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	if (*stack && (*stack)->next)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
	}

	else if (*stack)
	{
		free(*stack);
		*stack = NULL;
	}
}
