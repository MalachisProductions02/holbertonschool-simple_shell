#include "shell.h"

char *get_full_path(char *command);

/**
 * execute_command - executes a command (with or without PATH)
 * @line: the input string containing the command and its arguments,
 * separated by spaces (e.g., "ls -l /home").
 * Return: the exit status of the executed command, or 1 if an error occurs.
 */
int execute_command(char *line)
{
    pid_t pid;
    char *token, *cmd_to_exec;
    char *argv[MAX_ARGS];
    int i = 0;

    token = _strtok(line, " ");
    while (token && i < MAX_ARGS - 1)
    {
        argv[i++] = token;
        token = _strtok(NULL, " ");
    }
    argv[i] = NULL;

    if (argv[0] == NULL)
        return (0);

    pid = fork();
    if (pid == 0)
    {
        if (_strchr(argv[0], '/') != NULL)
        {
            cmd_to_exec = argv[0];
        }
        else
        {
            cmd_to_exec = get_full_path(argv[0]);
            if (!cmd_to_exec)
            {
                fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
                exit(127);
            }
        }

        freopen("/dev/null", "w", stdout);

        if (execve(cmd_to_exec, argv, environ) == -1)
        {
            fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
            if (cmd_to_exec != argv[0])
                free(cmd_to_exec);
            exit(127);
        }
    }
    else if (pid > 0)
    {
        int status;

        waitpid(pid, &status, 0);
        if (WEXITSTATUS(status) == 0)
        {
            write(STDOUT_FILENO, "OK\n", 3);
        }
        return (WEXITSTATUS(status));
    }
    else
    {
        perror("fork");
        return (1);
    }

    return (1);
}
