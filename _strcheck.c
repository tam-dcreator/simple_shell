#include "shell.h"
/**
 *_strcheck - Checks through a string to find a char.
 *@s: string.
 *@c: character to be located.
 *
 *
 *Return: Returns 0 if it found a string or 1 if it didn't.
 */
int _strcheck(const char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i++] == c)
			return (0);
	}
	return (1);
}
