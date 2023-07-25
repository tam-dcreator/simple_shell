#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 64
#define BUFFER_SIZE 1
/*Setting BUFFER_SIZE to 1 since there's a provision to always reallocate mem*/
extern char **environ;

void looper(char **envp);
char *readline(void);
void parse_args(char *line, char **args);
int is_builtin(char *command);
void execute_builtin(char **args);
int _strlen(const char *s);
char **tokenize(char *line);
void wait_for_child_process(pid_t pid);

#endif /* SHELL_H */
