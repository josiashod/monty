#include "monty.h"


/**
 * stack_push - pushes an element to the stack.
 *
 * @stack: pointer to the head of the stack
 * @line_number: the line number where the
 * instruction appears.
 */
void stack_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack;

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
	new_stack->prev = NULL;
	new_stack->next = *stack;
	if (*stack)
		(*stack)->prev = new_stack;
	*stack = new_stack;
}

/**
 * stack_pall - prints all the values on the stack,
 * starting from the top of the stack.
 *
 * @stack: pointer to the head of the stack
 * @line_number: the line number where the
 * instruction appears.
 */
void stack_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * stack_pint - prints the value at the top of the stack,
 * followed by a new line.
 *
 * @stack: pointer to the head of the stack
 * @line_number: the line number where the
 * instruction appears.
 */
void stack_pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		error = line_error(line_number, "can't pint, stack empty");
		return;
	}
	printf("%d\n", (*stack)->n);
}

/**
 * stack_pop - removes the top element of the stack.
 *
 * @stack: pointer to the head of the stack
 * @line_number: the line number where the
 * instruction appears.
 */
void stack_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!stack || !(*stack))
	{
		error = line_error(line_number, "can't pop an stack empty");
		return;
	}
	if ((*stack)->next)
		(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	free(tmp);
}

/**
 * stack_add - adds the top two elements of the stack.
 *
 * @stack: pointer to the head of the stack
 * @line_number: the line number where the
 * instruction appears.
 */
void stack_add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		error = stack_short_error(line_number, "add");
		return;
	}

	if (!(*stack) || !(*stack)->next)/* check if there is at least two el */
	{
		error = stack_short_error(line_number, "add");
		return;
	}

	(*stack)->next->n += (*stack)->n;
	stack_pop(stack, line_number);
}
