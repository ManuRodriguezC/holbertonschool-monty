#include "monty.h"

/**
 * get_opcode - compares instructions to opcodes and calls functions
 * Return: 0 on success, EXIT_FAILURE on error
 */

int get_opcode(void)
{
	instruction_t opfunctions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"add", op_add},
		{"pop", op_pop},
		{"pint", op_pint},
		{"swap", op_swap},
		{"nop", op_nop},
		{"sub", op_sub},
		{"mul", op_mul},
		{"div", op_div},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"#Comment", op_nop},
		{"#push", op_nop},
		{"#pall", op_nop},
		{NULL, NULL}};

	int i = 0;

	for (; opfunctions[i].opcode != NULL; i++)
	{
		if (strcmp(opfunctions[i].opcode, handle.rev_token) == 0)
		{
			opfunctions[i].f(&handle.head, handle.number_lines);
			break;
		}
	}

	if (!opfunctions[i].opcode)
	{
		fprintf(stderr, "L%ld: unknown instruction %s\n",
		handle.number_lines, handle.rev_token);
		free_structure();
		exit(EXIT_FAILURE);
	}

	return (0);
}
