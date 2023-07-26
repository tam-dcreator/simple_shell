#include "shell.h"

/**
 *full_path - makes a complete path from path.
 *@command: command to get a complete path for.
 *
 *Return: complete path.
  */
char *full_path(char *command)
{
	int i = 0;
	char *path, *token, *cwd, *temp[BUFFER_SIZE];
	struct stat sb;
	char c = '/';

	cwd = getcwd(NULL, 0);
	path = get_env("PATH");
	token = strtok(path, ":");

	while (token != NULL)
	{
		temp[i++] = token;
		token = strtok(NULL, ":");
	}
	temp[i] = NULL;

	i = 0;
	while (dirs[i] != NULL)
	{
		chdir(temp[i]);
		if (stat(command, &sb) == 0)
		{
			temp[i] = _strncat(temp[i], &c, 1);
			command = _strcat(temp[i], command);
			break;
		}
		i++;
	}
	chdir(cwd);
	return (command);
}
