#include "shell.h"

/**
 * get_env - Get the value of an environment variable.
 * @name: Name of the environment variable.
 *
 * Return: The value of the environment variable or NULL if not found.
 */
char *get_env(const char *name)
{
	extern char **environ;
	size_t name_len = _strlen(name);

	if (name == NULL || environ == NULL)
	return (NULL);

	(size_t i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		return (environ[i] + name_len + 1);
	}

	return (NULL);
}

