#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_ARGS 64
#define MAX_LINE_LENGTH 1024

/**
 * read_line - Read a line of input from the user.
 *
 * Return: The input line as a dynamically allocated string.
 */
char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1)
    {
        perror("read_line");
        exit(EXIT_FAILURE);
    }
    return (line);
}

/**
 * parse_args - Parse the input line into command arguments.
 * @line: Input line.
 * @args: Array to store the command arguments.
 */
void parse_args(char *line, char **args)
{
    int i = 0;
    char *token;
    const char *delimiters = " \t\r\n\a";

    token = strtok(line, delimiters);
    while (token != NULL && i < MAX_ARGS - 1)
    {
        args[i] = token;
        i++;
        token = strtok(NULL, delimiters);
    }
    args[i] = NULL;
}

/**
 * is_builtin - Check if the given command is a built-in command.
 * @command: Command to check.
 *
 * Return: 1 if the command is built-in, 0 otherwise.
 */
int is_builtin(char *command)
{
    if (strcmp(command, "cd") == 0 || strcmp(command, "exit") == 0)
        return (1);

    return (0);
}

/**
 * execute_builtin - Execute a built-in command.
 * @args: Command arguments.
 */
void execute_builtin(char **args)
{
    if (strcmp(args[0], "cd") == 0)
    {
        if (args[1] == NULL)
                fprintf(stderr, "%s: missing argument\n", args[0]);
        else if (chdir(args[1]) != 0)
                perror(args[0]);
        }
    else if (strcmp(args[0], "exit") == 0)
                exit(EXIT_SUCCESS);
}

/**
 * looper - Main loop for the shell program.
 * @env: Environment variables.
 *
 * Description: Reads commands from the user, executes them, and repeats
 * until the user exits.
 */
void looper(char **env)
{
    (void)env; /* Indicate that the 'env' parameter is intentionally unused */


    do {
        char *line;
          char *args[MAX_ARGS];
        printf("$ ");
        line = read_line();

        parse_args(line, args);

        if (args[0] != NULL)
        {
        if (is_builtin(args[0]))
                execute_builtin(args);
        else
           {
                pid_t pid = fork();

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
    } while (1);
}
