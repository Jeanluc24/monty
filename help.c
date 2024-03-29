#include "monty.h"

/**
 * free_stack - free stack
 * @stack: stack
 *
 * Return: nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *temp = NULL;

	if (*stack == NULL)
		return;
	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->prev;
		free(temp), temp = NULL;
	}
}

/**
 * is_empty - check if the stack is empty
 * @stack: stack
 *
 * Return: 1 if empty, 0 if not
 **/
int is_empty(stack_t *stack)
{
	return (stack == NULL);
}
