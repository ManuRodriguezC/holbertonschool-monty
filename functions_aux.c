#include "monty.h"

/**
 *
 *
 *
 */
void is_digit(char *str, unsigned int lines)
{
	int count;

	for (count = 0; str[count] != '\0'; count++)
	{
		if (str[count] < '0' || str[count] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", lines);
			exit(EXIT_FAILURE);
		}
	}
}
