#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

/**
 * builtin_cd - Changes the current directory of the process
 * @args: argument vector, args[0] is "cd", args[1] is the target directory
 * Return: 0 on success, -1 on failure
 */
int builtin_cd(char **args)
{
    char *dir;
    char *home;
    char *oldpwd;
    char cwd[1024];

    dir = args[1];
    home = _getenv("HOME");
    oldpwd = _getenv("OLDPWD");

    if (dir == NULL)
    {
        if (home == NULL)
            return (-1);
        dir = home;
    }
    else if (_strcmp(dir, "-") == 0)
    {
        if (oldpwd == NULL)
            return (-1);
        dir = oldpwd;
    }

    if (chdir(dir) != 0)
    {
        perror("cd");
        return (-1);
    }

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        if (home != NULL)
            _setenv("OLDPWD", home, 1);
        _setenv("PWD", cwd, 1);

        write(STDOUT_FILENO, cwd, _strlen(cwd));
        write(STDOUT_FILENO, "\n", 1);
    }

    return (0);
}
