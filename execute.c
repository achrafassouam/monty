#include "monty.h"
int global_number;

/**
 * execute - opens, reads and execute the codes
 * @argv: arguments
 *
 * Return: void
 */

void execute(char **argv)
{
	void (*function)(stack_t **, unsigned int);
	char *buffer = NULL, *token = NULL, cmd[1000];
	size_t buffer_size = 0;
	ssize_t linecap;
	FILE *fp;
	unsigned int line = 1;
	stack_t *top = NULL;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		file_open_error(argv);
	while ((linecap = getline(&buffer, &buffer_size, fp)) != EOF)
	{
		token = strtok(buffer, "\t\n ");
		if (token == NULL)
			continue;
		strcpy(cmd, token);
		if (is_comment(token, line) == 1)
			continue;
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\t\n ");
			if (token == NULL || is_number(token) == -1)
				not_int_error(line);
			global_number = atoi(token);
			function = op_code(cmd, line);
			function(&top, line);
		}
		else
		{
			function = op_code(token, line);
			function(&top, line);
		}
		line++;
	}
	fclose(fp);
	if (buffer != NULL)
		free(buffer);
	free_nodes(top);
}

/**
 * is_number - check if string received is int or not
 * @token: string to check
 * Return: -1 if sring is not int or 1 if yes
 */
int is_number(char *token)
{
	int i;

	if (token == NULL)
		return (-1);

	for (i = 0; token[i] != '\0'; i++)
	{
		if (token[i] != '-' && isdigit(token[i]) == 0)
			return (-1);
	}
	return (1);
}

/**
 * is_comment - check if the string is a comment
 * @token: pointer to string
 * @line_counter: line
 *
 * Return: -1 if not comment, 1 if it is
 */
int is_comment(char *token, int line_counter)
{
	if (token == NULL || token[0] == '#')
	{
		line_counter++;
		return (1);
	}
	return (-1);
}
