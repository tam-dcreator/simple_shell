#include "shell.h"
/**
 *main - Entry Function.
 *@ac: Argument count
 *@args: Argument vector
 *@envp: Array of environment strings
 *
 *Return: Always 0 on success
 */
int  main(__attribute__((unused)) int ac, char **args, char **envp)
{
	char *line = NULL;
	pid_t pid;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		line = readline();
		args = tokenize(line);
		if (args[0] != NULL)
		{
			if (is_builtin(args[0]))
				execute_builtin(args, line);
			else
			{
				pid = fork();
				if (pid == -1)
				{
					perror("In Looper, Fork");
					close_prog(args, line);
				}
				else if (pid == 0)
				{
					if (_strcheck(args[0], '/'))
						args[0] = full_path(args[0]);
					if (execve(args[0], args, envp) == -1)
					{
						perror(args[0]);
						close_prog(args, line);
					}
				}
				else
					wait_for_child_process(pid);
			}

		}
		free(args), free(line);
	}
	return (EXIT_SUCCESS);
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

/**
*close_prog - Function that frees memory and exits the program on error
*@args: Buffer containing the tokenized input
*@line: Buffer containing the command read from stdin
*
*/
void close_prog(char **args, char *line)
{
	free(args);
	free(line);
	exit(EXIT_FAILURE);
}
