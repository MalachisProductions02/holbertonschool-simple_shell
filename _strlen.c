#include "shell.h"

/**
 * _strlen - Returns ythe length of a string
 * @s: The string whose length is to be calculated
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int lenght = 0;

	while (s[lenght] != '\0')
	{
		lenght++;
	}

	return lenght;
}
