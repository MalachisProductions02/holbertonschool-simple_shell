#include "shell.h"

/**
 * _strncpy - Copia hasta n caracteres de la cadena src a dest.
 * @dest: El buffer de destino.
 * @src: La cadena fuente.
 * @n: Número máximo de caracteres a copiar.
 *
 * Return: El puntero a dest.
 */
char *_strncpy(char *dest, const char *src, int n)
{
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }

    for (; i < n; i++)
    {
        dest[i] = '\0';
    }

    return (dest);
}
