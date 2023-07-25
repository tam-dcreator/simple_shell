#include "shell.h"
/**
*simple_shell - Function that replicates a simple shell
*
*
*/

void simple_shell(void)
{
	char *args;

	while (true)
	{
		printf(":) ");
		args = readline();
		printf("%s\n", args);
		free(args);
	}
}
/*While loop*/
/*print prompt*/
/*readlines*/
/*tokenize*/
/*child process*/
/*execute token*/
/*wait for parent to finish*/
