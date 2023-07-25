#include "shell.h"

/**
 *looper - Main loop for the shell program.
 *@envp: Array of environment strings
 *
 *Description: Reads commands from the user, executes them, and repeats
 *until the user exits.
 */
void looper(char **envp)
{
	char *line = NULL;
	pid_t pid;
	char *args[MAX_ARGS];

	signal(SIGINT, SIG_IGN);
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
					perror("In Looper, Fork");
					exit(EXIT_FAILURE);
				}
				else if (pid == 0)
				{
					if (execve(args[0], args, envp) == -1)
					{
						perror(args[0]);
						exit(EXIT_FAILURE);
					}
				}
				else
					wait_for_child_process(pid);
			}

		}
		free(line);
	}
}

/**
*wait_for_child_process - Function that waits till a child process exited
*@pid: Process id of child
*
*/
void wait_for_child_process(pid_t pid)
{
	int status;
	pid_t wpid;

	do {
		wpid = wait(&status);
	} while (wpid != pid && !WIFEXITED(status) && !WIFSIGNALED(status));
}
