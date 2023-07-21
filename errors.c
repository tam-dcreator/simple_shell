#include "shell.h"

/**
 * print_error - Print an error message to stderr.
 * @prog_name: The name of the program (argv[0]).
 * @error_msg: The error message to print.
 */
void print_error(const char *prog_name, const char *error_msg)
{
	fprintf(stderr, "%s: %s\n", prog_name, error_msg);
}

/**
 * exit_failure - Exit the shell with a failure status.
 * @prog_name: The name of the program (argv[0]).
 */
void exit_failure(const char *prog_name)
{
	fprintf(stderr, "%s: Exiting with failure status.\n", prog_name);
	exit(EXIT_FAILURE);
}
