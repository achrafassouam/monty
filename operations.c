#include "monty.h"
/**
 * push_nodes - add a new node to the stack
 * @top: pointer to the top of the stack
 * @line_number: the line number
 *
 * Return: void
 */

void push_nodes(stack_t **top, unsigned int line_number)
{
	stack_t *new_node;
	int number = global_number;
	(void)line_number;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		malloc_error();

	new_node->n = number;
	new_node->prev = NULL;

	if (*top == NULL)
	{
		new_node->next = NULL;
		*top = new_node;
	}
	else
	{
		new_node->next = (*top);
		(*top)->prev = new_node;
		(*top) = new_node;
	}

}

/**
 * pall_nodes - print all nodes of the stack
 * @top: pointer to the top of the stack
 * @line_number: the line number
 *
 * Return: void
 */

void pall_nodes(stack_t **top, unsigned int line_number)
{
	stack_t *listptr = *top;
	(void)line_number;

	if (*top == NULL)
		return;

	while (listptr != NULL)
	{
		printf("%d\n", listptr->n);
		listptr = listptr->next;
	}
}

/**
 * free_nodes - free all memory allocation in the node
 * @top: pinter to the top of the stack
 *
 * Return: void
 */

void free_nodes(stack_t *top)
{
	stack_t *listptr;

	if (top == NULL)
		return;

	while (top != NULL)
	{
		listptr = top;
		top = top->next;
		free(listptr);
	}
	free(top);
}

/**
 * pint_nodes - print all nodes of the stack
 * @top: pointer to the top of the stack
 * @line_number: the line number
 *
 * Return: void
 */

void pint_nodes(stack_t **top, unsigned int line_number)
{
	stack_t *listptr = *top;
	(void)line_number;

	if (listptr != NULL)
		printf("%d\n", listptr->n);
	else
		pint_error(line_number);
}
