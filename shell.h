#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_ARGS 64
#define BUFFER_SIZE 1024

extern char **environ;

/*void looper(char **envp);*/
char *readline(void);
void parse_args(char *line, char **args);
int is_builtin(char *command);
void execute_builtin(char **args, char *line);
int _strlen(const char *s);
char **tokenize(char *line);
void wait_for_child_process(pid_t pid);
void close_prog(char **args, char *line);
int _atoi(const char *str);
int _strcheck(const char *s, char c);
char *full_path(char *command);
char *get_env(const char *name);
char *_strncat(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, int  n);
int _strcmp(const char *str1, const char *str2);
void print_error(const char *prog_name, const char *error_msg);

#endif /* SHELL_H */
