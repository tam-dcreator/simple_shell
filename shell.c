#include "shell.h"

/**
 *looper - Main loop for the shell program.
 *@env: Environment variables.
 *
 *Description: Reads commands from the user, executes them, and repeats
 *until the user exits.
 */
void looper(__attribute__((unused)) char **env)
{
	char *line;
	pid_t pid;
	char *args[MAX_ARGS];

	while (1)
	{
		printf("$ ");
		line = readline();
		parse_args(line, args);

		if (args[0] != NULL)
		{
			if (is_builtin(args[0]))
				execute_builtin(args);
			else
			{
				pid = fork();
				if (pid == -1)
				{
					perror("fork");
					exit(EXIT_FAILURE);
				}
				else if (pid == 0)
				{
					if (execve(args[0], args, env) == -1)
					{
						perror(args[0]);
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					wait(NULL);
				}
			}

		}
		free(line);
	}
}
