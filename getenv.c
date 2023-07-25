#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * get_env - Get the value of an environment variable.
 * @name: Name of the environment variable.
 *
 * Return: The value of the environment variable or NULL if not found.
 */
char *get_env(const char *name)
{
char **environ_ptr = environ;
size_t name_len = _strlen(name);

if (name == NULL || environ_ptr == NULL)
return (NULL);

while (*environ_ptr)
{
if (_strncmp(*environ_ptr, name, name_len) == 0 && (*environ_ptr)[name_len] == '=')
return (*environ_ptr + name_len + 1);
nviron_ptr++;
}

return (NULL);
}

