#include "monty.h"

/**
 * div_error - Print error if the stack contains less than two elements
 * @line: line
 * Return: void
 */
void div_error1(unsigned int line)
{
	fprintf(stderr, "L%u: can't div, stack too short\n", line);
	exit(EXIT_FAILURE);
}
/**
 * div_error2 - Print error if the top element of the stack is 0
 * @line: line
 * Return: void
 */
void div_error2(unsigned int line)
{
	fprintf(stderr, "L%u: division by zero\n", line);
	exit(EXIT_FAILURE);
}

/**
 * mul_error - if the stack contains less than two elements
 * @line: line
 * Return: void
 */

void mul_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't mul, stack too short\n", line);
	exit(EXIT_FAILURE);
}
