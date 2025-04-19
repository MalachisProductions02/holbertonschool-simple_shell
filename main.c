#include "shell.h"

int last_status = 0;

/**
 * main - Entry point of the shell
 * Return: 0 on success
 */
int main(void)
{
	signal(SIGINT, sigint_handler);
	shell_loop();
	return (0);
}
