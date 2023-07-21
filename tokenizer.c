#include "shell.h"

/**
 * tokenize - Tokenize a string into an array of tokens.
 * @line: The input string.
 *
 * Return: An array of tokens.
 */
char **tokenize(char *line)
{
	int bufsize = MAX_ARGS;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

	if (position >= bufsize)
	{
		bufsize += MAX_ARGS;
		tokens = realloc(tokens, bufsize * sizeof(char *));
		if (!tokens)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
	}

	token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}
