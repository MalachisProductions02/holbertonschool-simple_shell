#include "shell.h"

/**
 * trim_whitespace - Removes leading and trailing whitespace from a string
 * @str: The input string to be trimmed
 *
 * Return: Pointer to the trimmed string (within original buffer)
 */
char *trim_whitespace(char *str)
{
    char *end;

    while (*str == ' ')
        str++;

    if (*str == '\0')
        return (str);

    end = str + _strlen(str) - 1;

    while (end > str && (*end == ' ' || *end == '\n'))
        end--;

    *(end + 1) = '\0';

    return (str);
}

/**
 * shell_loop - Main loop of the simple shell
 * Displays prompt, reads input, and executes command
 */
void shell_loop(void)
{
    char *line = NULL;
    char *trimmed = NULL;
    char **args = NULL;
    size_t len = 0;
    ssize_t read;
    int status = 0;
    int i;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "#cisfun$ ", 9);

        read = custom_getline(&line, &len, STDIN_FILENO);
        if (read == -1)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            break;
        }

        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        trimmed = trim_whitespace(line);
        if (trimmed[0] == '\0')
            continue;

        args = split_line(trimmed);

        if (args && args[0] && args[0][0] != '\0')
        {
            if (_strcmp(args[0], "exit") == 0)
            {
                if (args[1] != NULL)
                {
                    int valid = 1;

                    i = 0;
                    while (args[1][i])
                    {
                        if (args[1][i] < '0' || args[1][i] > '9')
                        {
                            if (args[1][i] == '-' && i == 0 && args[1][i + 1] != '\0')
                            {
                                write(2, "./hsh: 1: exit: Illegal number: ", 32);
                                write(2, args[1], _strlen(args[1]));
                                write(2, "\n", 1);
                            }
                            else
                            {
                                write(2, "exit: numeric argument required\n", 32);
                            }
                            valid = 0;
                            break;
                        }
                        i++;
                    }
                    if (valid)
                        status = _atoi(args[1]);
                    else
                        status = 2;
                }
                else
                {
                    status = 0;
                }

                for (i = 0; args[i] != NULL; i++)
                    free(args[i]);
                free(args);
                free(line);
                exit(status);
            }
            else if (_strcmp(args[0], "env") == 0)
            {
                handle_env();
            }
            else if (_strcmp(args[0], "setenv") == 0)
            {
                if (args[1] && args[2])
                {
                    if (_setenv(args[1], args[2], 1) != 0)
                        write(2, "Failed to set environment variable\n", 35);
                }
                else
                {
                    write(2, "Usage: setenv VARIABLE VALUE\n", 29);
                }
            }
            else if (_strcmp(args[0], "unsetenv") == 0)
            {
                if (args[1])
                {
                    if (_unsetenv(args[1]) != 0)
                        write(2, "Failed to unset environment variable\n", 37);
                }
                else
                {
                    write(2, "Usage: unsetenv VARIABLE\n", 25);
                }
            }
            else if (_strcmp(args[0], "cd") == 0)
            {
                if (builtin_cd(args) != 0)
                    status = 2;
            }
            else
            {
                last_status = execute_command(trimmed);
                status = (last_status != 0) ? last_status : 0;
            }
        }

        if (args != NULL)
        {
            for (i = 0; args[i] != NULL; i++)
                free(args[i]);
            free(args);
        }
    }
    free(line);
    exit(status);
}
