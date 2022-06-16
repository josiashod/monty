#include "monty.h"

/**
 * queue_push - pushes an element to the queue.
 *
 * @stack: pointer to the head of the stack
 * @line_number: the line number where the
 * instruction appears.
 */
void queue_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack;
	stack_t *dlist = *stack;

	new_stack = malloc(sizeof(stack_t));
	if (!new_stack)
	{
		_stderr("Error: malloc failed\n");
		error = EXIT_FAILURE;
		return;
	}
	if (args[1] == NULL || !is_int(args[1]))
	{
		error = usage_error(line_number, "push", "integer");
		free(new_stack);
		return;
	}

	new_stack->n = atoi(args[1]);
	new_stack->next = NULL;
	new_stack->prev = NULL;

	if (!(*stack))
		*stack = new_stack;
	else
	{
		while (dlist->next)
			dlist = dlist->next;
		new_stack->prev = dlist;
		dlist->next = new_stack;
	}
}
