#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

ssize_t custom_getline(char **lineptr, size_t *n, int fd)
{
	static char buffer[BUFFER_SIZE];
	static size_t buf_pos, buf_size;
	char *new_line;
	char c;
	ssize_t len = 0;

	if (!lineptr || !n) return -1;
	if (*lineptr == NULL || *n == 0) {
		*n = 128;
		*lineptr = malloc(*n);
		if (!*lineptr) return -1;
	}

	while (1) {
		if (buf_pos >= buf_size) {
			buf_size  = read(fd, buffer, BUFFER_SIZE);
			if (buf_size <= 0) return (len > 0) ? len : -1;
			buf_pos = 0;
		}

		c = buffer[buf_pos++];
		(*lineptr)[len++] = c;

		if ((size_t)len >= *n) {
			*n *= 2;
			new_line = realloc(*lineptr, *n);
			if (!new_line) return -1;
			*lineptr = new_line;
		}

		if (c == '\n') break;
	}

	(*lineptr)[len] = '\0';
	return len;
}
