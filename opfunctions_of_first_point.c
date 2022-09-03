#include "monty.h"

/**
 *
 *
 *
 *
 */

void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	(void)line_number;

	if (!stack)
		exit(1);

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed");
		free_structure();
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(handle.copy_rev_token);
	new_node->prev = NULL;
	new_node->next = NULL;

	if (!*stack)
	{
		*stack = new_node;
		return;
	}
	new_node->next = *stack;
	(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 *
 */

void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void) line_number;

	for (; current; current = current->next)
		printf("%d\n", current->n);
}
