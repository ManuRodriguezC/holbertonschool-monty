#include "monty.h"

/**
 *
 *
 */

int interpreter_of_monty(void)
{
	while (getline(&handle.buffer, &handle.rev_size, handle.rev_file) != EOF)
	{
		handle.number_lines++;
		handle.rev_token = strtok(handle.buffer, DELIMIT);

		if (!handle.rev_token || handle.rev_token[0] == ' ')
			continue;

		if ((strcmp(handle.rev_token, "push") == 0))
		{
			handle.copy_rev_token = strtok(NULL, DELIMIT);
			if (!handle.copy_rev_token)
			{
				fprintf(stderr, "L%li: unknown instruction %s",
				handle.number_lines, handle.rev_token);
				exit(EXIT_FAILURE);
			}
			rev_is_digit();
		}
		get_opcode();
	}
	return (0);
}
