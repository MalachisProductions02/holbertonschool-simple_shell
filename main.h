#ifndef MAIN_H
#define MAIN_H

#define MAX_ARGS 64

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * int prototype
 * void prototype
 * char prototype
 */

extern char **environ;

void simple_shell(void);

int _putchar(char);
int add_numbers(int a, int b);

#endif /* MAIN_H */
