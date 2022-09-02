#include "monty.h"

/**
* free_dlistint - free a dlistint_t list
* @head: pointer to stack_t struct
**/

void free_dlistint(stack_t *head)
{
	stack_t *tmp = NULL;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
* free_all - frees allocated memory
* Return: Void
**/

void free_structure(void)
{
	free(handle.buffer);
	free_dlistint(handle.head);
	fclose(handle.rev_file);
}
