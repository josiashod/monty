#include "monty.h"

char **args = NULL;

/**
 * main - the main entry of the monty
 * interpretor
 * @argc: the number of arguments
 * @argv: array of arguments.
 *
 * Return: always 0.
 */
int main(int argc, char **argv)
{
	FILE *script;
	int exit_status = 0;

	if (argc != 2)
	{
		_stderr("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	script = fopen(argv[1], "r");

	if (!script)
	{
		_stderr("Error: Can't open file ");
		_stderr(strcat(argv[1], "\n"));
		exit(EXIT_FAILURE);
	}

	exit_status = run(script);
	exit(exit_status);
}
