#include "shell.h"

int last_status = 0;

/**
 * main - Entry point of the shell
 * Return: 0 on success
 */
int main(void)
{
	shell_loop();
	return (0);
}
