#include "monty.h"

/**
 * main - main function
 * @argc: arguments count
 * @argv: arguments table
 *
 * Return: 0 on Success, 1 on failure
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;

	/* check if the arguments are different to 2*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* reading the file*/
	read_file(argv[1], &stack);
	if (!is_empty(stack))
	{
		free_stack(&stack);
	}
	return (0);
}
