#include "shell.h"

/**
 *is_builtin - Check if the given command is a built-in command.
 *@command: Command to check.
 *
 *Return: 1 if the command is built-in, 0 otherwise.
 */
int is_builtin(char *command)
{
	if (_strcmp(command, "cd") == 0 || _strcmp(command, "exit") == 0 ||
		_strcmp(command, "env") == 0)
		return (1);

	return (0);
}

/**
 *execute_builtin - Execute a built-in command.
 *@args: Command arguments.
 *@line: Buffer where command from stdin where read into
 *
 *Description: Not really a description, just noting that i sent the line var
 *into this function just so i can free it if user types exit.
 */
void execute_builtin(char **args, char *line)
{
	int status;

	if (_strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
			print_error(args[0]);
		else if (chdir(args[1]) != 0)
			perror(args[0]);
	}
	else if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			status = _atoi(args[1]);
			if (status == '\0')
				close_prog(args, line);
			free(args), free(line), exit(status);
		}
		free(args), free(line), exit(EXIT_SUCCESS);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		print_environ();
	}
}
