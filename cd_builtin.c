#include "shell.h"

/**
 * builtin_cd - Changes the current working directory.
 * @args: Arguments passed to "cd" (args[0] = "cd", args[1] = path or NULL).
 *
 * Return: 0 on success, -1 on error.
 */
int builtin_cd(char **args)
{
    char *path, *home, *oldpwd;
    char cwd[1024];

    home = _getenv("HOME");
    oldpwd = _getenv("OLDPWD");

    if (!args[1] || _strcmp(args[1], "~") == 0)
    {
        if (!home)
            return (-1);
        path = home;
    }
    else if (_strcmp(args[1], "-") == 0)
    {
        if (!oldpwd)
        {
            write(STDERR_FILENO, "OLDPWD not set\n", 15);
            return (-1);
        }
        path = oldpwd;
        write(STDOUT_FILENO, path, _strlen(path));
        write(STDOUT_FILENO, "\n", 1);
    }
    else
    {
        path = args[1];
    }

    if (chdir(path) != 0)
    {
        perror("cd");
        return (-1);
    }

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        _setenv("OLDPWD", _getenv("PWD"), 1);
        _setenv("PWD", cwd, 1);
    }
    else
    {
        perror("getcwd");
        return (-1);
    }

    return (0);
}
