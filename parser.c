#include "shell.h"
/**
 * parse_args - Parse the input line into command arguments.
 * @line: Input line.
 * @args: Array to store the command arguments.
 */
void parse_args(char *line, char **args)
{
	int i = 0;
	char *token;
	const char *delimiters = " \t\r\n\a";

	token = strtok(line, delimiters);
	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, delimiters);
	}
	args[i] = NULL;
}
