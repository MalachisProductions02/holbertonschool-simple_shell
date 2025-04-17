#include "main.h"

/**
 * execute_command - forks and runs a command using execve
 * @line: full path to command, no args
 */
void execute_command(char *line)
{
	pid_t pid;
	int status;
	char *argv[] = {line, NULL};

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
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
