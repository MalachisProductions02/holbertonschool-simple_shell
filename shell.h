#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
 * int prototype
 * void prototype
 * char prototype
 */
extern char **environ;

void shell_loop(void);
void execute_command(char *command);

#endif /* SHELL_H */
