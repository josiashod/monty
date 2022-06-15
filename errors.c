#include "monty.h"


/**
 * _stderr - print error message on
 * stderr
 * @message: The error message
 */
void _stderr(char *message)
{
	fprintf(stderr, "%s", message);
}


/**
 * invalid_opcode - print the invalid
 * opcode error
 *
 * @l_num: the line number where
 * the instruction appears.
 * @opcode: the unknown opcode
 *
 * Return: always EXIT_FAILURE
 */
size_t invalid_opcode(unsigned int l_num, char *opcode)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", l_num, opcode);
	return (EXIT_FAILURE);
}

/**
 * line_error - print the error find
 * on a line
 * @l_num: the line number where
 * the instruction appears.
 * @message: the error message
 *
 * Return: always EXIT_FAILURE
 */
size_t line_error(unsigned int l_num, char *message)
{
	fprintf(stderr, "L%u: %s\n", l_num, message);
	return (EXIT_FAILURE);
}

/**
 * usage_error - print the invalid
 * usage error for an opcode
 *
 * @l_num: the line number where
 * the instruction appears.
 * @opcode: the unknown opcode
 * @message: the message of the error
 *
 * Return: always EXIT_FAILURE
 */
size_t usage_error(unsigned int l_num, char *opcode, char *message)
{
	fprintf(stderr, "L%u: usage: %s %s\n", l_num, opcode, message);
	return (EXIT_FAILURE);
}
