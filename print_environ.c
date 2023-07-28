#include "shell.h"

/**
 *print_environ - prints all the environment variables.
 *
 *Return: nothing.
 */
void print_environ(void)
{
	int i;
	char newline = '\n';

	i = 0;
	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, &newline, 1);
		i++;
	}
}
