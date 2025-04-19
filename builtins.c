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
    int i = 0, name_len, value_len;

    if (!name || !value || name[0] == '\0' || _strchr(name, '=') != NULL)
        return (-1);

    name_len = _strlen(name);
    value_len = _strlen(value);

    while (environ[i])
    {
        if (_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
        {
            if (!overwrite)
                return (0);
            break;
        }
        i++;
    }

    new_var = malloc(name_len + value_len + 2);
    if (!new_var)
        return (-1);

    _strcpy(new_var, name);
    new_var[name_len] = '=';
    _strcpy(new_var + name_len + 1, value);
    new_var[name_len + value_len + 1] = '\0';

    environ[i] = new_var;
    environ[i + 1] = NULL;
    return (0);
}

/**
 * _unsetenv - Removes an environment variable
 * @name: Name of the variable to remove
 * Return: 0 on succes, -1 on failure
 */
int _unsetenv(const char *name)
{
    int i = 0, j;
    size_t len = _strlen(name);

    if (!name || name[0] == '\0' || _strchr(name, '=') != NULL)
        return (-1);

    while (environ[i])
    {
        if (_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
        {
            free(environ[i]);
            for (j = i; environ[j]; j++)
                environ[j] = environ[j + 1];
            return (0);
        }
        i++;
    }
    return (0);
}
