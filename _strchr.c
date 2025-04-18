#include "shell.h"

/**
 * _strchr - Locates the first occurrence of a character in a string
 * @s: The string to search
 * @c: The character to find
 * Return: Pointer to the first occurrence of c in s, or NULL if not found
 */
char *_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (char *)s;
		s++;
	}
	return  NULL;
}
