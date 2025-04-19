#include "shell.h"
#include <stdlib.h>

/**
 * split_line - Split a line into tokens (words)
 * @line: The line to split
 *
 * Return: Null-terminated array of tokens
 */
char **split_line(char *line)
{
	int bufsize = 64, position = 0;
	char **tokens = malloc(sizeof(char *) * bufsize);
	char *start = line, *end;

	if (!tokens)
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}

	while (*start != '\0')
	{
		while (*start == ' ' || *start == '\t')
			start++;

		if (*start == '\0')
			break;

		end = start;
		while (*end != '\0' && *end != ' ' && *end != '\t')
			end++;

		int length = end - start;
		tokens[position] = malloc(length + 1);
		if (!tokens[position])
		{
			perror("allocation error");
			exit(EXIT_FAILURE);
		}
		_strcpy(tokens[position], start, length);
		tokens[position][length] = '\0';
		position++;
		
		start = end;
	}

	tokens[position] = NULL;
	return tokens;
}
