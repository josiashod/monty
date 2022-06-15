#include "monty.h"

/**
 * _isdigit - checks for a digit (0 through 9).
 *
 *@c: the character to check
 *
 * Return: On success 1.
 * On error 0.
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * is_int - check the given string can be
 * used as an integer
 * @str: the given string
 *
 * Return: 1 on success, 0 on fail
 */
int is_int(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		else if (!_isdigit(str[i]))
			return (0);
	}
	return (1);
}
