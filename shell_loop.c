#include "shell.h"

/**
 * builtin_cd - Changes the current directory of the process
 * @args: argument vector, args[0] is "cd", args[1] is the target directory
 * Return: 0 on success, -1 on failure
 */
int builtin_cd(char **args)
{
    char *dir, *home, *oldpwd, cwd[PATH_MAX];

    oldpwd = getcwd(cwd, sizeof(cwd));

    if (args[1] == NULL)
    {
        home = _getenv("HOME");
        if (!home)
            return (-1);
        if (chdir(home) != 0)
            return (-1);
    }
    else if (_strcmp(args[1], "-") == 0)
    {
        char *old = _getenv("OLDPWD");
        if (!old)
            return (-1);
        if (chdir(old) != 0)
            return (-1);
        write(STDOUT_FILENO, old, _strlen(old));
        write(STDOUT_FILENO, "\n", 1);
    }
    else
    {
        dir = args[1];
        if (chdir(dir) != 0)
            return (-1);
    }

    setenv("OLDPWD", oldpwd, 1);

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        setenv("PWD", cwd, 1);
    }

    return (0);
}
