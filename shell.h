#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 64
#define BUFFER_SIZE 1024

typedef struct list_t list_t;
typedef struct info_t info_t;

/* Function prototypes from strlen.c */
int _strlen(char *s);

/* Function prototypes */
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
char *starts_with(const char *s, const char *prefix);

/* Environment-related functions */
char **list_to_strings(list_t *list);
int delete_node_at_index(list_t **head, unsigned int index);
char **get_environ(info_t *info);
int _unsetenv(info_t *info, char *var);
int _setenv(info_t *info, char *var, char *value);


/* Other functions used in the provided code */
void print_error(const char *prog_name, const char *error_msg);
void exit_failure(const char *prog_name);
ssize_t input_buf(info_t *info, char **buf, size_t *len);
ssize_t get_input(info_t *info);
ssize_t read_buf(info_t *info, char *buf, size_t *i);
int _getline(info_t *info, char **ptr, size_t *length);
void sigintHandler(__attribute__((unused)) int sig_num);
char *get_env(const char *name);
int is_builtin(char *command);
void execute_builtin(char **args);
void parse_args(char *line, char **args);
void looper(__attribute__((unused)) char **env);

/* Function prototypes from tokenizer.c */
char **tokenize(char *line);

/* Function prototype for readline */
char *readline(const char *prompt);

/* Function prototype for add_node_end */
void add_node_end(list_t **head, char *str);

#endif /* SHELL_H */

