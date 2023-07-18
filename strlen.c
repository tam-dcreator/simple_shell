#include "shell.h"

/**
 *_strlen - Function to get the length of a string
 *@s: String to be evaluated
 *
 *Return: Total length of string
 */
int _strlen(char *s)
{
	int count = 0;

	while (s[count] != '\0')
		count++;
	return (count);
}
