#include "shell.h"

/**
 * _strcpy - Copies the string pointed to by src, including the null byte
 * @dest: Destination buffer
 * @src: Source string
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;


	if (dest == NULL || src == NULL)
		return (NULL);

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
