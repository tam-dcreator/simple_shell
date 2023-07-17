#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 64

void looper(char **env);
char *read_line(void);
void parse_args(char *line, char **args);
int is_builtin(char *command);
void execute_builtin(char **args);

#endif /* SHELL_H */
