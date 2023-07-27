#include "shell.h"

/**
 *print_error - Print an error message to stderr.
 *@prog_name: The name of the program (argv[0]).
 *@error_msg: The error message to print.
 */
void print_error(const char *prog_name, const char *error_msg)
{
	write(2, prog_name, _strlen(prog_name));
	write(2, error_msg, _strlen(error_msg));
}
