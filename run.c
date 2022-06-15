#include "monty.h"

/**
 * free_args - frees args array
 */
void free_args(void)
{
	int i;

	if (args)
	{
		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
		free(args);
	}
}

/**
 * is_empty_line - check if the current line contains only
 * delimiter
 * @line: the line
 *
 * Return: 1 on success, 0 on failure
 */
int is_empty_line(char *line)
{
	while (*line)
	{
		if (!is_delim(*line, DELIMS))
			return (0);
		line++;
	}
	return (1);
}

/**
 * get_op_func - function that return
 * the function of the opcode
 *
 * @opcode: the opcode
 * Return: function on success, NULL on fails
 */
void (*get_op_func(char *opcode))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{"pint", stack_pint},
		{NULL, NULL}
	};

	while (ops[i].opcode != NULL && strcmp(ops[i].opcode, opcode))
		i++;
	return (ops[i].f);
}

/**
 * run - function that run program
 * @script: the file descriptor of the monty bytecodes scripts
 *
 * Return: On success return EXIT_SUCCESS
 * otherwise return a failure code
 */
size_t run(FILE *script)
{
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS, line_number = 0;
	stack_t *stack = NULL;
	void (*op_func)(stack_t **stack, unsigned int line_number);

	while (getline(&line, &len, script) != -1)
	{
		line_number++;
		args = strtow(line, DELIMS);
		if (args == NULL)
		{
			if (is_empty_line(line))
				continue;
			_stderr("Error: malloc failed\n");
			exit_status = EXIT_FAILURE;
			break;
		}
		op_func = get_op_func(args[0]);
		if (op_func == NULL)
		{
			exit_status = invalid_opcode(line_number, args[0]);
			break;
		}
		op_func(&stack, line_number);
		if (error == EXIT_FAILURE)
		{
			exit_status = error;
			free_args();
			break;
		}
		free_args();
	}
	if (line && *line == 0)
	{
		exit_status = EXIT_FAILURE;
		_stderr("Error: malloc failed\n");
	}
	free(line);
	free_stack(&stack);
	return (exit_status);
}
