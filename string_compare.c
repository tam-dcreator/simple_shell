#include "shell.h"
/**
*_strcmp - Compare two strings.
*@str1: First string
*@str2: Second string
*
*Return: The difference between both strings.
*/
int _strcmp(const char *str1, const char *str2)
{
	while ((*str1 != '\0') && (*str2 != '\0') && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*str1 - *str2);
}

/**
*_strncmp - Function that compares n number of chars
*@s1: First string
*@s2: Second string
*@n: Number of chars to compare
*
*Return: The difference or zero
*/
int _strncmp(const char *s1, const char *s2, int  n)
{
	int i;

	for (i = 0; i < n;)
	{
		if ((s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i]))
			i++;
		else
		{
			if (s1[i] == '\0' || s2[i] == '\0')
				return (0);
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}
