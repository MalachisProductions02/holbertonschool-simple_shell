#include "shell.h"

char *get_full_path(char *command);

/**
 * execute_command - executes a command (with or without PATH)
 * @command: the command to run (e.g. ls, /bin/ls, ./hbtn_ls)
 */
void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		char *argv[2];
		char *cmd_to_exec;

		argv[0] = command;
		argv[1] = NULL;

		if (strchr(command, '/') != NULL)
		{
			cmd_to_exec = command;
		}
		else
		{
			cmd_to_exec = get_full_path(command);
			if (cmd_to_exec == NULL)
			{
				fprintf(stderr, "./shell: command not found: %s\n", command);
				exit(EXIT_FAILURE);
			}
		}

		if (execve(cmd_to_exec, argv, environ) == -1)
		{
            /* this helps to use others paths */
			perror(cmd_to_exec);
			if (cmd_to_exec != command)
				free(cmd_to_exec);
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
