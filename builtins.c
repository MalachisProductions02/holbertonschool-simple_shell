#include "shell.h"

/**
 * _setenv - Sets or updates and environment variable
 * @name: Name of the variable
 * @value: Value of the variable
 * @overwrite: 1 to overwrite existing value, 0 to keep
 * Return: 0 on succes, -1 on failure
 */
#include "shell.h"

/**
 * _setenv - set or update an environment variable
 * @name: name of the variable
 * @value: value to set
 * @overwrite: if 0, don't overwrite existing variable
 *
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
    char *new_var;
    int name_len, value_len;

    if (!name || !value || name[0] == '\0')
        return (-1);

    if (getenv(name) != NULL && overwrite == 0)
        return (0);

    name_len = _strlen(name);
    value_len = _strlen(value);

    new_var = malloc(name_len + value_len + 2);
    if (!new_var)
        return (-1);

    _strcpy(new_var, name);
    new_var[name_len] = '=';
    _strcpy(new_var + name_len + 1, value);

    if (putenv(new_var) != 0)
    {
        free(new_var);
        return (-1);
    }

    return (0);
}

/**
 * _unsetenv - Removes an environment variable
 * @name: Name of the variable to remove
 * Return: 0 on succes, -1 on failure
 */
int _unsetenv(const char *name)
{
    int i, j, len_name;

    if (!name || name[0] == '\0')
        return (-1);

    len_name = strlen(name);

    for (i = 0; environ[i]; i++)
    {
        if (strncmp(environ[i], name, len_name) == 0 && environ[i][len_name] == '=')
        {
            for (j = i; environ[j]; j++)
                environ[j] = environ[j + 1];
            return (0);
        }
    }
    return (0);
}
