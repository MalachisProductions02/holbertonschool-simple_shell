#include "shell.h"
#include <string.h>

/**
 * _strncmp - Compare two strings up to n characters
 * @s1: First string
 * @s2: Second string
 * @n: Max number of characters to compare
 *
 * Return: 0 if strings are equal up to n, difference between first differing chars otherwise
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
    while (n && *s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
        n--;
    }
    if (n == 0)
        return (0);
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
