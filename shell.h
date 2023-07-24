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
size_t _strlen(const char *s);
char *get_env(const char *name);
int strncmp(const char *s1, const char *s2, size_t n);

#endif /* SHELL_H */
