#include "monty.h"

/**
 * init_stack - initialize a stack
 *
 * Return: pointer to the new stack
 * on success, NULL on failed
 */
stack_t *init_stack()
{
	stack_t *new_s;

	new_s = malloc(sizeof(stack_t));
	if (!new_s)
		return (NULL);
	new_s->n = 0;
	new_s->prev = NULL;
	new_s->next = NULL;

	return (new_s);
}

/**
 * free_stack - frees a stack
 * @stack: Pointer to the top of
 * the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
