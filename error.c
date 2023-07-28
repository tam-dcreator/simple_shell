#include "shell.h"

/**
 *print_error - Print an error message to stderr.
 *@prog_name: The name of the program (args[0]).
 *
 */
void print_error(const char *prog_name)
{
	fprintf(stderr, "./hsh: %d: %s: %s\n", errno, prog_name,
		strerror(errno));
}
