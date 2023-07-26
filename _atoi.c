#include "shell.h"

/**
 * _atoi - Convert a string to an integer.
 * @str: The string to convert.
 *
 * Return: The integer value.
 */
int _atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return ('\0');

		result = result * 10 + (str[i] - '0');
	}

	return (sign * result);
}
