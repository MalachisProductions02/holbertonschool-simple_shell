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

	/* Skip leading whitespace */
	while (*str == ' ')
		str++;

	/* Return if empty */
	if (*str == '\0')
		return (str);

	/* Move to the end */
	end = str + strlen(str) - 1;

	/* Trim trailing whitespace and newlines */
	while (end > str && (*end == ' ' || *end == '\n'))
		end--;

	/* Terminate after last non-whitespace character */
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

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		trimmed = trim_whitespace(line);

        /* implement exit command */
        if (strcmp(trimmed, "exit") == 0)
        {
            break;
        }

		if (trimmed[0] != '\0')
			execute_command(trimmed);
	}

	free(line);
}
