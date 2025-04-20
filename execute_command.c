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

    /* Tokenize input into argv */
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
            cmd_to_exec = argv[0];  /* Command contains full path */
        }
        else
        {
            cmd_to_exec = get_full_path(argv[0]);  /* Look for command in PATH */
            if (!cmd_to_exec)  /* Command not found */
            {
                fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
                exit(127);  /* Exit with status 127 for command not found */
            }
        }

        if (execve(cmd_to_exec, argv, environ) == -1)  /* Execute the command */
        {
            fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
            if (cmd_to_exec != argv[0])
                free(cmd_to_exec);
            exit(127);  /* Exit with status 127 if execve fails */
        }
    }
    else if (pid > 0)
    {
        int status;

        waitpid(pid, &status, 0);  /* Wait for child process to finish */
        return (WEXITSTATUS(status));  /* Return exit status of child process */
    }
    else
    {
        perror("fork");  /* Error creating the child process */
        return (1);  /* Return 1 in case of error */
    }

    return (1);  /* This line should never be reached */
}
