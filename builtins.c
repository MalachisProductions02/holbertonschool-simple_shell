#include "shell.h"

/**
 * _setenv - Sets or updates and environment variable
 * @name: Name of the variable
 * @value: Value of the variable
 * @overwrite: 1 to overwrite existing value, 0 to keep
 * Return: 0 on succes, -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	if (!name || !value)
		return (-1);

	if (overwrite == 0 && gatenv(name) != NULL)
		return (0);

	if (setenv(name, value, 1) != 0)
	{
		perror("setenv");
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
	if (!name)
		return (-1);

	if (unsetenv(name) != 0)
	{
		perror("unsetenv");
		return (-1);
	}

	return (0);
}
