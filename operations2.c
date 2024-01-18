#include "monty.h"

/**
 * swap_nodes - swaps the elemets of the stack
 * @top: pointer to the top of the stack
 * @line_number: number of the line
 *
 * Return: void
 */

void swap_nodes(stack_t **top, unsigned int line_number)
{
	int value;

	if (*top == NULL || (*top)->next == NULL)
		swap_error(line_number);

	value = (*top)->n;
	(*top)->n = (*top)->next->n;
	(*top)->next->n = value;
}

/**
 * add_nodes - add elements of the node
 * @top: pointer to the top of the stack
 * @line_number: number of the line
 *
 * Return: void
 */
void add_nodes(stack_t **top, unsigned int line_number)
{
	if (*top == NULL || (*top)->next == NULL)
		add_error(line_number);

	(*top)->next->n += (*top)->n;

	pop_nodes(top, line_number);
}

/**
 * nop_nodes - doesn’t do anything
 * @top: pointer to the top of the stack
 * @line_number: number of the line
 *
 * Return: void
 */
void nop_nodes(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;
}

/**
 * sub_nodes - sub top elements of the stack
 * @top: pointer to the top of the stack
 * @line_number: number of the line
 *
 * Return: void
 */

void sub_nodes(stack_t **top, unsigned int line_number)
{
	stack_t *lineptr;

	if (*top == NULL || (*top)->next == NULL)
		sub_error(line_number);

	lineptr = (*top)->next;
	lineptr->n -= (*top)->n;
	pop_nodes(top, line_number);
}

/**
 * div_nodes - Divides elements of the stack
 * @top: pointer to top element of the stack
 * @line_number: number of line
 *
 * Return: void
 */

void div_nodes(stack_t **top, unsigned int line_number)
{
	stack_t *lineptr;

	if (*top == NULL || (*top)->next == NULL)
		div_error1(line_number);

	if ((*top)->n == 0)
		div_error2(line_number);

	lineptr = (*top)->next;
	lineptr->n = (lineptr->n) / (*top)->n;
	pop_nodes(top, line_number);
}
