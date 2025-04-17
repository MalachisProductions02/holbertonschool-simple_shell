#include "main.h"

void simple_shell(void)
{
    char *line = NULL, *token, *args[MAX_ARGS];
    char *full_path = NULL;
    size_t len = 0;
    ssize_t read;
    pid_t pid;
    int status, i;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "#cisfun$ ", 9);

        read = getline(&line, &len, stdin);
        if (read == -1)
            break;

        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        i = 0;
        token = strtok(line, " ");
        while (token && i < MAX_ARGS - 1)
            args[i++] = token, token = strtok(NULL, " ");
        args[i] = NULL;

        if (!args[0])
            continue;
        if (strcmp(args[0], "exit") == 0)
            break;
        if (strcmp(args[0], "env") == 0)
        {
            for (i = 0; environ[i]; i++)
                printf("%s\n", environ[i]);
            continue;
        }
	
	if (access(args[0], X_OK) == 0)
	{
		full_path = args[0];
	}
	else
	{
		full_path = get_full_path(args[0]);
		if (!full_path)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			continue;
		}
	}

        pid = fork();
        if (pid == 0)
        {
            if (execve(args[0], args, environ) == -1)
            {
                perror("./hsh");
                exit(EXIT_FAILURE);
            }
        }
        else if (pid > 0)
            waitpid(pid, &status, 0);
        else
            perror("fork");
    }

    if (full_path != args[0])
        free(full_path);
}
