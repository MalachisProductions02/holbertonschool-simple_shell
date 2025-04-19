#include "shell.h"

/**
 * _strncpy - Copies up to n characters from the source string to the destination buffer
 * @dest: The destination buffer where the string will be copied
 * @src: The source string to copy from
 * @n: The maximum number of characters to copy
 *
 * Return: Pointer to the destination buffer
 */
char *_strncpy(char *dest, const char *src, int n)
{
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];

    for (; i < n; i++)
        dest[i] = '\0';

    return dest;
}
