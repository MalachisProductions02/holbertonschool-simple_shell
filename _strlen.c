#include "shell.h"

/**
 * _strlen - Returns ythe length of a string
 * @s: The string whose length is to be calculated
 *
 * Return: The length of the string
 */
int _strlen(const char *s)
{
    int len = 0;

    while (s[len] != '\0')
        len++;

    return len;
}
