#include "shell.h"

/**
 * trim_whitespace - Removes leading and trailing whitespace from a string
 * @str: The input string to be trimmed
 *
 * Return: Pointer to the trimmed string (within original buffer)
 */
char *trim_whitespace(char *str)
{
	char *end;

	while (*str == ' ')
		str++;

	if (*str == '\0')
		return (str);

	end = str + _strlen(str) - 1;

	while (end > str && (*end == ' ' || *end == '\n'))
		end--;

	*(end + 1) = '\0';

	return (str);
}

/**
 * shell_loop - Main loop of the simple shell
 * Displays prompt, reads input, and executes command
 */
void shell_loop(void)
{
	char *line = NULL;
	char *trimmed = NULL;
	char **args = NULL;
	size_t len = 0;
	ssize_t read;
	int status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		read = custom_getline(&line, &len, STDIN_FILENO);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		trimmed = trim_whitespace(line);
		if (trimmed[0] == '\0')
			continue;

		args = split_line(trimmed);

		if (args && args[0] && args[0][0] != '\0')
		{
			if (_strcmp(args[0], "exit") == 0)
			{
				if (args[1] != NULL)
				{
					int i = 0, valid = 1;

					while (args[1][i])
					{
						if (args[1][i] < '0' || args[1][i] > '9')
						{
							write(2, "exit: numeric argument required\n", 32);
							valid = 0;
							break;
						}
						i++;
					}
					if (valid)
						status = _atoi(args[1]);
					else
						status = 2;
				}
				free(args);
				free(line);
				exit(status);
			}
			else if (_strcmp(args[0], "env") == 0)
			{
				handle_env();
			}
			else
			{
				last_status = execute_command(trimmed);
			}
		}
		free(args);
	}
	free(line);
	exit(last_status);
}
