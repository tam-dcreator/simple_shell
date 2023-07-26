#include "shell.h"
/**
*read_line - Function that reads lines from standard inputs using read().
*
*Return: The null terminated string of inputs.
*
*/

char *read_line(void)
{
	char *args;
	ssize_t bytesread, totalread = 0;

	args = malloc(BUFFER_SIZE);

	if (args == NULL)
	{
		perror("Failed to allocate memory to read from file");
		exit(EXIT_FAILURE);
	}

	bytesread = read(STDIN_FILENO, args, BUFFER_SIZE - 1);

	if (bytesread == -1)
	{
		perror("Error reading from file");
		exit(EXIT_FAILURE);
	}

	while (bytesread == BUFFER_SIZE)
	{
		totalread += bytesread;
		args = realloc(args, totalread + BUFFER_SIZE);
		if (args == NULL)
		{
			perror("Failed to allocate memory to read from file");
			exit(EXIT_FAILURE);
		}

		bytesread = read(STDIN_FILENO, args + totalread, BUFFER_SIZE);

		if (bytesread == -1)
		{
			perror("Error reading from file");
			exit(EXIT_FAILURE);
		}
	}
	args[totalread + bytesread] = '\0';
	return (args);
}