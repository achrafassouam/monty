#include"monty.h"

/**
 * main - main entry, Monty bytecodes files interpreter
 * @argc: argument count
 * @argv: arguments
 *
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	if (argc != 2)
		argument_error();
	execute(argv);

	return (0);
}
