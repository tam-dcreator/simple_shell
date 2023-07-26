#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
*main - Entry function
*
*
*Return: On success, Always 0
*/
int main(void)
{
	size_t size = 1;
	char *string, *buf;

	buf = malloc(sizeof(char) * size);
	if (!buf)
	{
		perror("In Main, Malloc");
		exit(EXIT_FAILURE);
	}
	string = getcwd(buf, size);
	while (string == NULL)
	{
		size += 1;
		buf = realloc(buf, size);
		if (!buf)
		{
			perror("In Main, Realloc");
			exit(EXIT_FAILURE);
		}
		string = getcwd(buf, size);
	}
	printf("%s\n", string);
	free(buf);
	return (0);
}