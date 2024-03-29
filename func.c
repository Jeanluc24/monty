#include "monty.h"

/**
 * push - push element to the stack
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *layer = malloc(sizeof(stack_t));

	(void)line_number;
	if (layer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	layer->n = get_arg();
	layer->next = NULL;
	layer->prev = *stack;
	if (!is_empty(*stack))
	{
		(*stack)->next = layer;
	}
	*stack = layer;
}

/**
 * pall - print the elements of the stack
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	while (tmp != NULL)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->prev;
	}
}

/**
 * pint - print the top most stack node
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * pop - delete the top most layer of the stack
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (is_empty(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev == NULL)
	{
		(*stack)->next = NULL;
		free(*stack), *stack = NULL;
	}
	else
	{
		tmp = *stack;
		/*shouldn't stack -> next == NULL?*/
		*stack = (*stack)->prev;
		tmp->prev = NULL;
		tmp->next = NULL;
		free(tmp), tmp = NULL;
	}
}

/**
 * swap - swap the top two elements of the slack
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = tmp;
}
