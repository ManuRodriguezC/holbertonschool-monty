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

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(command_glob);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 *
 *
 *
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 *
 *
 *
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	int count = 0, change;
	stack_t *temp = *stack;

	while (temp)
	{
		count++;
		temp = temp->next;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	change = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = change;
}

/**
 *
 *
 *
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
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

/**
 *
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
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
	else
	{
		dprintf(2, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
}
