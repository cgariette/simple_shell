#ifndef SHELL_H
#define SHELL_H

#define BUFF_SIZE 1024

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

int _putchar(char c);
void execmd(char **argv);
char *get_path(char *cmd);
#endif
