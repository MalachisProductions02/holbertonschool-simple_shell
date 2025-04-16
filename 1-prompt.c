#include "main.h"
#include <string.h>

/**
 * main - Simple shell
 * Return: 0 on succes, 1 on error
 */
int main(void)
{
	char *line = NULL;
	char *args[100];
	char *token = strtok(line, " ");
	size_t len = 0;
	ssize_t read;
	int i = 0;
	pid_t pid;

	while (1)
	{
		write(1, "#cisfun$ ", 9);

		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			free(line);
			exit(0);
		}

		if (line[read - 1] == '\n')
			line[read - 1] == '\0';

		while (token != NULL && i < 99)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

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
