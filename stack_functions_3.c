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
