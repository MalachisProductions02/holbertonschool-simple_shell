#include "shell.h"

/**
 * _strcpy - Copies a string from source to destination
 * @dest: The destination buffer where the string will be copied
 * @src: The source string to copy
 *
 * Return: Pointer to the destination buffer
 */
char *_strcpy(char *dest, const char *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
