#include "shell.h"

/**
 * execute_command - executes a command without PATH or arguments
 * @command: the command to run (e.g. /bin/ls)
 */
void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		char *argv[2];

		argv[0] = command;

		argv[1] = NULL;

		if (execve(command, argv, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		int status;

		waitpid(pid, &status, 0);
	}
	else
	{
		perror("fork");
	}
}
