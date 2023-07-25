#include "shell.h"
/**
*main - Entry Function.
*@ac: Argument count
*@av: Argument vector
*@envp: Array of environment strings
*
*Return: Always 0 on success
*/
int  main(__attribute__((unused)) int ac,
	  __attribute__((unused)) char **av, char *envp[])
{

	looper(envp);

	return (EXIT_SUCCESS);
}
