#include "monty.h"
/**
 * _getline - read a line of input descriptor
 * @lineptr: line pointer
 * @n: n
 * @stream: file stream
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int c;
	size_t i;
	char *temp;

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			fprintf(stderr, "Error: failed to alloc. mem");
			exit(EXIT_FAILURE);
		}
	}

	i = 0;
	while ((c = fgetc(stream)) != EOF)
	{
		(*lineptr)[i++] = (char)c;

		if (i == *n - 1)
		{
			*n *= 2;
			temp = (char *)realloc(*lineptr, *n);
			if (temp == NULL)
			{
				fprintf(stderr, "Out of memory");
				exit(EXIT_FAILURE);
			}
			*lineptr = temp;
		}

		if (c == '\n')
			break;

	}
	(*lineptr)[i] = '\0';
	return (i);

}

int _isascii(int c)
{
	return (c >= 0 && c <= 127);
}
