#include "monty.h"

/**
 *
 *
 *
 *
 */
int main(int argc, char **argv)
{
	FILE *rev_file;
	int number_lines = 0;
	char *buffer = NULL, *rev_token = NULL, *copy_rev_token = NULL;
	size_t rev_size = 0;
	void (*rev_opcode)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	
	rev_file = fopen(argv[1], "r");
	if (rev_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &rev_size, rev_file) != EOF)
	{
		number_lines++;

		rev_token = strtok(buffer, DELIM);
		if (!rev_token || rev_token[0] == ' ')
			continue;
		
		copy_rev_token = strtok(NULL, DELIM);

		if (strcmp(rev_token, "push") == 0)
		{
			is_digit(copy_rev_token, number_lines);
			command_glob = strdup(copy_rev_token);

			if (!copy_rev_token)
			{
				fprintf(stderr, "L%u: usage: push integer\n", number_lines);
				free(buffer);
				exit(EXIT_FAILURE);
			}	
		}

		rev_opcode = get_opcode(rev_token);

		if (rev_opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s", number_lines, rev_token);
			exit(EXIT_FAILURE);
		}
	return (0);
	}

}
