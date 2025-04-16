#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

/**
 * main - Simple shell
 * Return: 0 on success, 1 on error
 */
int main(void)
{
    char *line = NULL;
    char *args[100];
    size_t len = 0;
    ssize_t read;
    pid_t pid;
    int i;

    while (1)
    {
        write(1, "#cisfun$ ", 9);

        read = getline(&line, &len, stdin);

        if (read == -1)
        {
            free(line);
            exit(0);
        }

        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        i = 0;
        char *token = strtok(line, " ");

        while (token != NULL && i < 99)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        pid = fork();
        if (pid == 0)
        {
            if (execve(args[0], args, environ) == -1)
                perror("./shell");
            exit(1);
        }
        else if (pid > 0)
            wait(NULL);
        else
            perror("Error:");
    }

    free(line);
    return (0); /* Times that I corrected the code: 3 */
}
