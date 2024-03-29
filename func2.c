#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element of
 * the stack by the top element of the stack.
 * and operate pop, unless top == zero
 * @stack: stack
 * @line_number: line_number
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int top = 0;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->prev->n % (*stack)->n;
	(*stack)->prev->n = top;
	pop(stack, line_number);
}

/**
 * pchar - print the top most value as a char if not out of range
 * @stack: stack
 * @line_number: line_number
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack, followed
 * by a new line, while the interger being treated as an ascii value
 * @stack: stack
 * @line_number: line_number
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	if (tmp == NULL)
	{
		putchar('\n');
		return;
	}

	while (tmp && (tmp->n < 128 && tmp->n > 0))
	{
		fprintf(stdout, "%c", tmp->n);
		tmp = tmp->prev;
	}
	putchar('\n');
}

/**
 * rotl - prints the string starting at the top of the stack, followed
 * by a new line, while the interger being treated as an ascii value
 * @stack: stack
 * @line_number: line_number
 * Return: nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL, *first_rotl = NULL;

	(void)line_number;
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		return;
	}
	first_rotl = *stack;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	first_rotl->prev = NULL;
	first_rotl->next = NULL;
	tmp = *stack;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	tmp->prev = first_rotl;
	first_rotl->next = tmp;
}

/**
 * rotr - prints the string starting at the top of the stack, followed
 * by a new line, while the interger being treated as an ascii value
 * @stack: stack
 * @line_number: line_number
 * Return: nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL, *first_rotr = *stack, *last_rotr = NULL;
	(void)line_number;
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		return;
	}
	tmp = *stack;
	while (tmp->prev->prev != NULL)
		tmp = tmp->prev;
	last_rotr = tmp->prev;
	last_rotr->next = NULL;
	tmp->prev = NULL;
	last_rotr->prev = first_rotr;
	first_rotr->next = last_rotr;
	*stack = last_rotr;
}
