#include "monty.h"

/**
 * pint_error - print error message if list is empty
 * @line: line
 * Return: void
 */
void pint_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line);
	exit(EXIT_FAILURE);
}

/**
 * pop_error - print error message is list is empty
 * @line: line
 * Return: void
 */
void pop_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line);
	exit(EXIT_FAILURE);
}
