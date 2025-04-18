#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGS 64

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * int prototype
 * void prototype
 * char prototype
 */
extern char **environ;

/**
 * last_status - stores the exit status of the last executed command.
 */
extern int last_status;

void shell_loop(void);
int execute_command(char *command);
char *get_full_path(char *command);
void handle_env(void);

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _atoi(char *s);

ssize_t custom_getline(char **lineptr, size_t *n, int fd);

char *_strtok(char *str, const char *delim);
char *_strchr(const char *s, char c);
char *_strcpy(char *dest, const char *src);
char **split_line(char *line);

#endif /* SHELL_H */
