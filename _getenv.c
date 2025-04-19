#include "shell.h"

/**
 * _getenv - Custom implementation of getenv
 * Retrieves the value of an environment variable
 * @name: The name of the environment variable to search for
 *
 * Return: Pointer to the value string if found, or NULL if not found
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t len;

	if (name == NULL || name[0] == '\0')
		return (NULL);

	len = _strlen(name);

	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (environ[i] + len + 1);

		i++;
	}

	return (NULL);
}
