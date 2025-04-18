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
	size_t len = 0;
	ssize_t read;
	int status = 0;
	int i = 0;

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

		if (_strcmp(trimmed, "exit") == 0)
		{
			free(line);
			exit(last_status);
		}

		if (_strcmp(trimmed, "env") == 0)
		{
			handle_env();
			continue;
		}
		if (trimmed[0] != '\0')
			last_status = execute_command(trimmed);

		if (_strcmp(args[0], "exit") == 0)
		{
			if (args[1][i] != NULL)
			{
				while (args[1][i] != '\0')
				{
					if (args[1][i] < '0' || args[1][i] > '9')
					{
						write(2, "exit: numeric argument required\n", 32);
						return (1);
					}
					i++;
				}
				status = _atoi(args[1]);
			}
			exit(status);
		}
	}
	free(line);
	exit(last_status);
}
