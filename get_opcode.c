#include "monty.h"

/**
 *
 *
 *
 *
 */
void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", op_push},
		{NULL, NULL}};

	int i = 0;

	for (; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		       return (opcodes[i].f);	
	}
	return (NULL);


}
