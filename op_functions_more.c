#include "monty.h"

/**
 * op_add - Function that adds the top two elements of the stack.
 * @stack: Stack structure
 * @line_number: Number of line in the file
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
			fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	(tmp->next)->n = tmp->n + (tmp->next)->n;
	op_pop(stack, line_number);
}

/**
 * op_nop - Functions that doesn’t do anything.
 * @stack: Stack structure
 * @line_number: Number of line in the file
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * op_sub - This functions subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: Stack structure.
 * @line_number: Number of line in the file.
 */
void op_sub(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp->next->n = temp->next->n - temp->n;
	op_pop(stack, line_number);
}

/**
 * op_div - This function divides the second top element of the stack
 * by the top element of the stack.
 * @stack: Stack structure.
 * @line_number: Number of line in the file.
 */
void op_div(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
 * op_mul - The function multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack: Stack structure.
 * @line_number: Number of line in the file.
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *temp = *stack;
	int count;

	while (stack)
	{
		count++;
		current = current->next;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp->next->n = temp->next->n * temp->n;
	op_pop(stack, line_number);
}
