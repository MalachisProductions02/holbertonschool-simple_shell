#include "main.h"

void execute_command(char *line);

/**
 * main - Entry point of simple shell
 * Return: Always 0
 */
int main(void)
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
			break;
		}

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		if (line[0] != '\0')
			execute_command(line);
	}

	free(line);
	return (0);
}
