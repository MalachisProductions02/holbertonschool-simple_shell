#include "shell.h"

/**
 * _strtok - Splits a string into tokens based on delimiters
 * @str: The string to tokenize. pass NULL to continue tokenizing the same string
 * @delim: The delimiter characters
 * Return: A pointer to the next token, or NULL if no more tokens are found
 */
char *_strtok(char *str, const char *delim)
{
	static char *backup;
	char *token;

	if (str != NULL)
		backup = str;
	if (backup == NULL)
		return NULL;

	while (*backup && strchr(delim, *backup))
		backup++;

	if (*backup == '\0') return NULL;

	token = backup;

	while (*backup && !strchr(delim, *backup))
		backup++;

	if (*backup) {
		*backup = '\0';
		backup++;
	} else {
		backup = NULL;
	}

	return token;
}
