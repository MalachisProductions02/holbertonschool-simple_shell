#include "shell.h"

char *get_full_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy, *token, *full_path;
	int len;

	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	token = strtok(path_copy, ":");
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
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
