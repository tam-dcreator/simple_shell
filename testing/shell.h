#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

void simple_shell(void);
char *readline(void);
char *read_line(void);

#endif/*SHELL_H*/
