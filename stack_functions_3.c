#include "monty.h"

/**
 * stack_swap - swaps the top two elements of the stack.
 *
 * @stack: pointer to the head of the stack
 * @line_number: the line number where the
 * instruction appears.
 */
void stack_swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (!stack || !(*stack))
	{
		error = stack_short_error(line_number, "swap");
		return;
	}

	if (!(*stack) || !(*stack)->next)/* check if there is at least two el */
	{
		error = stack_short_error(line_number, "swap");
		return;
	}

	tmp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = tmp;
}

/**
 * stack_pchar - prints the char at the top of the stack,
 * followed by a new line.
 *
 * @stack: pointer to the head of the stack
 * @line_number: the line number where the
 * instruction appears.
 */
void stack_pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		error = line_error(line_number, "can't pchar, stack empty");
		return;
	}

	if (!isascii((*stack)->n))/* check if is out of range */
	{
		error = line_error(line_number, "can't pchar, value out of range");
		return;
	}

	printf("%c\n", (*stack)->n);
}

/**
 * stack_pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 *
 * @stack: pointer to the head of the stack
 * @line_number: the line number where the
 * instruction appears.
 */
void stack_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	while (tmp && tmp->n && isascii((*stack)->n))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
	(void)line_number;
}

/**
 * stack_rotl - rotate a stack
 * The top element of the stack becomes the last one,
 * and the second top element of the stack
 * @stack: pointer to the head of the stack
 * @line_number: the line number where the
 * instruction appears.
 */
void stack_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = *stack;
	bottom = *stack;

	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = NULL;
	(*stack) = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}

/**
 * stack_rotr - rotate a stack
 * The last element of the stack becomes
 * the top element of the stack
 * @stack: pointer to the head of the stack
 * @line_number: the line number where the
 * instruction appears.
 */
void stack_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = *stack;
	bottom = *stack;

	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	top->prev = bottom;
	bottom->next = top;
	bottom->prev = NULL;
	(*stack) = bottom;

	(void)line_number;
}
