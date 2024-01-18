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
