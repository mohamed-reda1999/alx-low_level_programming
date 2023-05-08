#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *ch;
	ssize_t sz;
	ssize_t ws;
	ssize_t ts;

	sz = open(filename, O_RDONLY);
	if (sz == -1)
		return (0);
	ch = malloc(sizeof(char) * letters);
	ts = read(sz, ch, letters);
	ws = write(STDOUT_FILENO, ch, ts);

	free(ch);
	close(sz);
	return (ws);
}
