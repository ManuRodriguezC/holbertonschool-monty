#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#define DELIMIT " $\n"

/**
 * struct handler - helper functions
 * @token2: pointer to token 1
 * @buffer: pointer to string returned from getline
 * @fp: pointer to file
 * @head: pointer to beginning of list
 * @line_number: line number of file
 * @n: number of bytes read
 * @token1: pointer to token 2
 * @queueflag: flag for queue function
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 **/

typedef struct handlers
{
	char *copy_rev_token;
	char *buffer;
	FILE *rev_file;
	stack_t *head;
	size_t number_lines;
	size_t rev_size;
	char *rev_token;
} handler;
extern handler handle;

/* Protipypes */

int main(int argc, char **argv);
int interpreter_of_monty(void);
void rev_is_digit(void);
int get_opcode(void);
void op_push(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_add(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void free_structure(void);


extern char *command_glob;
char *command_glob;
extern stack_t *command_glob_head;
stack_t *command_glob_head;

#endif
