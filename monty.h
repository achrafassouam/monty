#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>

extern int global_number;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Main Functions */
void execute(char **argv);
void (*op_code(char *token, unsigned int line))(stack_t **, unsigned int);



/* error handler functions */
void file_open_error(char **argv);
void argument_error(void);
void instructions_error(char *invInstruction, unsigned int line);
void malloc_error(void);
void not_int_error(unsigned int line);
void pint_error(unsigned int line);
void pop_error(unsigned int line);
void swap_error(unsigned int line);
void add_error(unsigned int line);


/* operation functions */
void push_nodes(stack_t **top, unsigned int line_number);
void pall_nodes(stack_t **top, unsigned int line_number);
void free_nodes(stack_t *top);
void pint_nodes(stack_t **top, unsigned int line_number);
void pop_nodes(stack_t **top, unsigned int line_number);
void swap_nodes(stack_t **top, unsigned int line_number);
void add_nodes(stack_t **top, unsigned int line_number);
void nop_nodes(stack_t **top, unsigned int line_number);

/* other functions */
int is_comment(char *token, int line_counter);
int is_number(char *token);


#endif
