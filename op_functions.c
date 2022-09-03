#include "monty.h"

/**
 * op_push - Insert to node in the satack
 * @stack: structure stack.
 * @line_number: NUmber of lines in file
 */

void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	(void)line_number;

	if (!stack)
	{
		exit(1);
	}

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
 * op_pall - Functiosn that print all nodes in stack
 * @stack: structure stack.
 * @line_number: NUmber of lines in file
 */

void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void) line_number;

	for (; current; current = current->next)
		printf("%d\n", current->n);
}

/**
 * op_pop - Function that removes the top element of the stack.
 * @stack: structure stack.
 * @line_number: NUmber of lines in file
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

/**
 * op_swap - Function that swaps the top two elements of the stack.
 * @stack: structure stack.
 * @line_number: NUmber of lines in file
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

/**
 * op_pint - Function that  prints the value at the top of the stack,
 * followed by a new line.
 * @stack: structure stack.
 * @line_number: NUmber of lines in file
 */

void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
