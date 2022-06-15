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
size_t invalid_opcode(int l_num, char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s", l_num, opcode);
	return (EXIT_FAILURE);
}
