#include "main.h"

/**
 * read_textfile - reads a text file and prints to standard output
 * @filename: Pointer to where to start in text file
 * @letters: number of letters to read and print
 *
 * Return: Actual number of letters read and printed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t lenread, lenwrite;
	char *buf;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}

	lenread = read(fd, buf, letters);
	close(fd);
	if (lenread == -1)
	{
		free(buf);
		return (0);
	}

	lenwrite = write(STDOUT_FILENO, buf, lenread);
	free(buf);
	if (lenread != lenwrite)
		return (0);
	return (lenwrite);
}
