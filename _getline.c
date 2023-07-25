#include "shell.h"
/**
*readline - Function to read the characters inputs from the command line.
*
*Return: A pointer to the memory location where the read chars are stored.
*/
char *readline(void)
{
	int bufsize = BUFFER_SIZE;
	int ch, index = 0;
	static char *buffer;

	buffer = malloc(sizeof(char) * bufsize);
	if (!buffer)
	{
		perror("In Readline, Malloc");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		ch = getc(stdin);

		if (ch == EOF || ch == '\n')
		{
			buffer[index] = '\0';
			return (buffer);
		}
		else
		{
			buffer[index++] = ch;
		}

		/* If we have exceeded the buffer size, reallocate memory.*/
		if (index >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				perror("In Readline, Realloc");
				exit(EXIT_FAILURE);
			}
		}
	}
}
