#include "monty.h"

/**
 * mul_nodes - multipy elements of the stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 */
void mul_nodes(stack_t **top, unsigned int line_number)
{
	stack_t *lineptr;

	if (*top == NULL || (*top)->next == NULL)
		mul_error(line_number);

	lineptr = (*top)->next;
	lineptr->n *= (*top)->n;
	pop_nodes(top, line_number);
}

/**
 * mod_nodes - modulo of the elements
 * @top: poitner of the top of the list
 * @line_number: number of the line
 *
 * Return: NULL
 */

void mod_nodes(stack_t **top, unsigned int line_number)
{
	stack_t *lineptr;

	if (*top == NULL || (*top)->next ==  NULL)
		mod_error(line_number);

	if ((*top)->n == 0)
		div_error2(line_number);

	lineptr = (*top)->next;
	lineptr->n = (lineptr->n) % (*top)->n;
	pop_nodes(top, line_number);
}
