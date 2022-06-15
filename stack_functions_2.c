#include "monty.h"

/**
 * stack_nop - doesn’t do anything.
 *
 * @stack: pointer to the head of the stack
 * @line_number: the line number where the
 * instruction appears.
 */
void stack_nop(stack_t **stack, unsigned int line_number)
{
	return;
}


/**
 * stack_sub - subs the top two elements of the stack.
 *
 * @stack: pointer to the head of the stack
 * @line_number: the line number where the
 * instruction appears.
 */
void stack_sub(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		error = stack_short_error(line_number, "sub");
		return;
	}

	if (!(*stack) || !(*stack)->next)/* check if there is at least two el */
	{
		error = stack_short_error(line_number, "sub");
		return;
	}

	(*stack)->next->n -= (*stack)->n;
	stack_pop(stack, line_number);
}
