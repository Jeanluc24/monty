#include "monty.h"

/**
 * add - Add first layer data to the sencond top one, and
 * remove the top
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n + (*stack)->prev->n;
	(*stack)->prev->n = tmp;
	pop(stack, line_number);
}

/**
 * nop - print the elements of the stack
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - subtract the top from the soocnd to layer
 * and operate pop
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->prev->n = (*stack)->prev->n - (*stack)->n;
	pop(stack, line_number);
}

/**
 * divide - div divides the second top element of the stack by the top
 * element of the stack.
 * and operate pop, unless top == zero
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int top = 0;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->prev->n / (*stack)->n;
	(*stack)->prev->n = top;
	pop(stack, line_number);
}

/**
 * mul - multiplies the second top element of the stack with the
 * top element of the stack.
 * and operate pop.
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int top = 0;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = (*stack)->prev->n * (*stack)->n;
	(*stack)->prev->n = top;
	pop(stack, line_number);
}
