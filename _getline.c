#include "shell.h"
/**
*readline - Function to read the characters inputs from the command line.
*
*Return: A pointer to the memory location where the read chars are stored.
*/
char *readline(void)
{
	int bufsize = BUFFER_SIZE;
	int index = 0;
	size_t count;
	char *temp, *buffer = malloc(sizeof(char) * bufsize);

	if (!buffer)
	{
		perror("In Readline, Malloc");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		count = read(STDIN_FILENO, buffer + index, bufsize - index);
		if (count <= 0)
			break;

		index += count;
		if (buffer[index - 1] == '\n')
			break;

		if (index >= bufsize - 1)
		{
			bufsize += BUFFER_SIZE;
			temp = realloc(buffer, bufsize);
			if (!temp)
			{
				perror("In Readline, Realloc");
				free(buffer), exit(EXIT_FAILURE);
			}
			buffer = temp;
		}
	}
	if (index == 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[index] = '\0';
	return (buffer);
}
