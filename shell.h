#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 64
#define BUFFER_SIZE 1024

void looper(char **env);
char *readline(void);
void parse_args(char *line, char **args);
int is_builtin(char *command);
void execute_builtin(char **args);
int _strlen(char *s);

#endif /* SHELL_H */
