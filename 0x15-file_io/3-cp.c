#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *files);
void close_file(int ifd);

/**
 * create_buffer - Allocates 1024 bytes for a chbuf.
 * @files: The name of the file chbuf is storing chars for.
 *
 * Return: A pointer to the newly-allocated chbuf.
*/

char *create_buffer(char *files)
{
	char *chbuf;

	chbuf = malloc(sizeof(char) * 1024);

	if (chbuf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", files);
		exit(99);
	}

	return (chbuf);
}

/**
 * close_file - Closes file descriptors.
 * @ifd: The file descriptor to be closed.
*/

void close_file(int ifd)
{
	int clo;

	clo = close(ifd);

	if (clo == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", ifd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
*/

int main(int argc, char *argv[])
{
	int ifrom, ito, ir, iw;
	char *chbuf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	chbuf = create_buffer(argv[2]);
	ifrom = open(argv[1], O_RDONLY);
	ir = read(ifrom, chbuf, 1024);
	ito = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (ifrom == -1 || ir == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(chbuf);
			exit(98);
		}

		iw = write(ito, chbuf, ir);
		if (ito == -1 || iw == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(chbuf);
			exit(99);
		}

		ir = read(ifrom, chbuf, 1024);
		ito = open(argv[2], O_WRONLY | O_APPEND);

	} while (ir > 0);

	free(chbuf);
	close_file(ifrom);
	close_file(ito);

	return (0);
}
