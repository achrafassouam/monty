#include "monty.h"

/**
 * op_code - containes the operation code functions
 * @token: the opertion code
 * @line: the line
 *
 * Return: void
 */
void (*op_code(char *token, unsigned int line))(stack_t **, unsigned int)
{
	instruction_t operations[] = {
		{"push", push_nodes},
		{"pall", pall_nodes},
		{"pint", pint_nodes},
		{"pop", pop_nodes},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{NULL, NULL}
	};
	int i;

	for (i = 0; operations[i].opcode != NULL; i++)
	{
		if (strcmp(token, operations[i].opcode) == 0)
			return (operations[i].f);
	}

	instructions_error(token, line);
	return (NULL);
}
