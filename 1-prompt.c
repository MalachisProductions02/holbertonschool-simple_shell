#include "main.h"

/**
 * main - Simple shell
 * Return: 0 on succes, 1 on error
 */
int main(void)
{
	char *line = NULL;
	suize_t len = 0;
	ssize_t read;
	pid_t pid;

	while (1)
	{
		write(1, "#cisfun$ ", 9);

		read = getline(&line, &len, stdin);

		if (read == -1);
		{
			free(line);
			exit(0);
		}

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		pid = fork();
		if (pid == 0)
		{
			if (execve(line, NULL, environ) == -1)
				perror("./shell");
			exit(1);
		}
		else if (pid > 0)
			wait(NULL);
		else
			perror("Error:");
	}

	free(line);
	return (0);
}
