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
    char *prev_pwd;
    char cwd[1024];

    dir = args[1];
    prev_pwd = _getenv("PWD");

    if (dir == NULL)
    {
        home = _getenv("HOME");
        if (home == NULL)
            return (-1);
        dir = home;
    }
    else if (_strcmp(dir, "-") == 0)
    {
        oldpwd = _getenv("OLDPWD");
        if (oldpwd == NULL)
            return (-1);
        dir = oldpwd;
        write(STDOUT_FILENO, dir, _strlen(dir));
        write(STDOUT_FILENO, "\n", 1);
    }

    if (chdir(dir) != 0)
    {
        perror("cd");
        return (-1);
    }

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        if (prev_pwd != NULL)
            _setenv("OLDPWD", prev_pwd, 1);
        _setenv("PWD", cwd, 1);
    }

    return (0);
}
