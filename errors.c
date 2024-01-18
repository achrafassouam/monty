#include "monty.h"

/**
 * argument_error - Prints an error message for invalid arguments
 * and exits with failure status.
 */
void argument_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * instructions_error - Prints an error message for an unknown instruction
 * @invInstruction: The unknown instruction
 * @line: The line number where the instruction appears
 *
 * Exits with failure status
 */
void instructions_error(char *invInstruction, unsigned int line)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line, invInstruction);
	exit(EXIT_FAILURE);
}

/**
 * file_open_error - Prints an error message if a file cannot be opened.
 * @argv: Argument vector passed to the program.
 */
void file_open_error(char **argv)
{
	char *filename = argv[1];

	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * not_int_error - Prints an error message for non-integer input
 * @line: The line number where the error occurred
 */
void not_int_error(unsigned int line)
{
	fprintf(stderr, "L%u: usage: push integer\n", line);
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - Prints an error message and exits if malloc fails.
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
