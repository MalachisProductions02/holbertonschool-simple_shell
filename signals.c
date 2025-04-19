#include <stdio.h>
#include <unistd.h>
#include <signal.h>

/**
 * sigint_handler - Handles the Ctrl+C signal (SIGINT)
 * @sig: The signal number
 */
void sigint_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n#cisfun$ ", 9);
}
