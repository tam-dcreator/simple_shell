#include "shell.h"

/**
 * set_var - Set a variable in the environment.
 * @name: Variable name.
 * @value: Variable value.
 *
 * Return: 0 on success, -1 on failure.
 */
int set_var(char *name, char *value)
{
	char *var;
	int len;

	len = strlen(name) + strlen(value) + 2;
	var = malloc(len * sizeof(char));
	if (!var)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	snprintf(var, len, "%s=%s", name, value);
	if (putenv(var) != 0)
	{
		perror("putenv");
		free(var);
		return (-1);
	}

	return (0);
}

/**
 * unset_var - Unset a variable from the environment.
 * @name: Variable name.
 *
 * Return: 0 on success, -1 on failure.
 */
int unset_var(char *name)
{
	if (unsetenv(name) != 0)
	{
		perror("unsetenv");
		return (-1);
	}

	return (0);
}
