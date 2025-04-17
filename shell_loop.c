#include "shell.h"

/**
 * trim_whitespace - Removes leading and trailing whitespace from a string
 * @str: The input string to be trimmed
 *
 * Return: Pointer to the trimmed string
 */
char *trim_whitespace(char *str)
{
	char *end;

	/* Move the pointer forward while there are leading spaces */
	while (*str == ' ')
		str++;

	/* If the string is empty after trimming spaces */
	if (*str == '\0')
		return (str);

	/* Find the end of the string */
	end = str + strlen(str) - 1;

	/* Move the end pointer backward */
	while (end > str && (*end == ' ' || *end == '\n'))
		end--;

	/* Null-terminate the string after the last non-space character */
	*(end + 1) = '\0';

	return (str);
}

/**
 * shell_loop - main loop of the shell
 */
void shell_loop(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		/* Remove newline */
line = trim_whitespace(line);

		if (line[0] != '\0') /* no empty input */
			execute_command(line);
	}

}
