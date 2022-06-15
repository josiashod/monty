#include "monty.h"

char **args = NULL;
size_t error = EXIT_SUCCESS;

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
	size_t exit_status;

	if (argc != 2)
	{
		_stderr("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	script = fopen(argv[1], "r");

	if (!script)
	{
		_stderr("Error: Can't open file ");
		_stderr(argv[1]);
		_stderr("\n");
		exit(EXIT_FAILURE);
	}
fclose(script):

	exit_status = run(script);
	exit(exit_status);
}
