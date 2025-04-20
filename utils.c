#include "shell.h"

/**
 * get_full_path - Retrieves the full path of a command by
 * searching in the PATH
 * @command: The command to search for
 *
 * Return: Pointer to the full path if found, NULL otherwise.
 */
char *get_full_path(char *command)
{
    char *path = getenv("PATH");
    char *path_copy, *token, *full_path;
    int len;

    if (!path || path[0] == '\0')
        return (NULL);

    path_copy = strdup(path);
    if (!path_copy)
        return (NULL);

    token = _strtok(path_copy, ":");
    while (token)
    {
        len = snprintf(NULL, 0, "%s/%s", token, command) + 1;
        full_path = malloc(len);
        if (!full_path)
        {
            free(path_copy);
            return (NULL);
        }

        snprintf(full_path, len, "%s/%s", token, command);
        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return (full_path);
        }
        free(full_path);
        token = _strtok(NULL, ":");
    }
    free(path_copy);
    return (NULL);
}

/**
 * handle_env - Prints the current environment
 */
void handle_env(void)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
