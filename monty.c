#include "monty.h"

/**
 * main - Main program instructions
 * @argc: total of arguments
 * @argv: The arguments, monty files
 * Return: int
 */

int main(int argc, char **argv)
{
	handle.number_lines = 0;
	handle.rev_size = 0;
	handle.rev_token = NULL;
	handle.head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	handle.rev_file = fopen(argv[1], "r");
	if (handle.rev_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	interpreter_of_monty();
	free_structure();

	return (0);
}
