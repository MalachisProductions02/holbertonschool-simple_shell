#include "main.h"

/**
 * main - Simple shell that handles single-word commands with full path
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t pid;
	int status;

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

		/* Remove newline character */
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		if (line[0] == '\0')
			continue;

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			continue;
		}
		else if (pid == 0)
		{
			/* command is a single word without args */
			char *argv[] = {line, NULL};

			if (execve(line, argv, environ) == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}

	return (0);
}