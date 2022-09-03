#include "monty.h"

/**
 * rev_is_digit - determines if string is number
 * Return: 0 on success, exits on failure
 */

void rev_is_digit(void)
{
	int count = 0;

	if ((!isdigit(handle.copy_rev_token[0]) && handle.copy_rev_token[0] != '-') ||
	(handle.copy_rev_token[0] == '-' && handle.copy_rev_token[1] == '\0'))
	{
		fprintf(stderr, "L%lu: usage: push integer\n", handle.number_lines);
		exit(EXIT_FAILURE);
	}

	count = 1;
	for (; handle.copy_rev_token[count] != '\0'; count++)
	{
		if (!isdigit(handle.copy_rev_token[count]))
		{
			fprintf(stderr, "L%lu: usage: push integer\n", handle.number_lines);
			free_structure();
			exit(EXIT_FAILURE);
		}
	}
}
