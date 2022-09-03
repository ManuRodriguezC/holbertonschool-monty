#include "monty.h"

/**
 * op_mod - The function computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @stack: Stack structure.
 * @line_number: Number of line in the file.
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	stack_t *current = *stack;
	int count = 0;

	while (current)
	{
		count++;
		current = current->next;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp->next->n = temp->next->n / temp->n;
	op_pop(stack, line_number);
}

/**
 * op_pchar - The function prints the char at the top of the stack,
 * followed by a new line.
 * @stack: Stack structure.
 * @line_number: Number of line in the file.
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int value = temp->n;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(*stack);
		exit(EXIT_FAILURE);
	}

	if (temp->n < 65 || temp->n > 122)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", value);
}

/**
 * op_pstr - The function  prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: Stack structure.
 * @line_number: Number of line in the file.
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp->n < 65 || temp->n > 122)
	{
		exit(0);
	}

	while (temp)
	{
		if (temp->n == (0 + '0') || (temp->n < (0 + '0') || temp->n > (255 + '0')))
		{
			printf("\n");
			exit(0);
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
