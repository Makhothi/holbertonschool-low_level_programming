#include "main.h"
#include "string.h"

/**
 * append_text_to_file - Adds text to end of existing file
 * @filename: name of file to be created
 * @text_content: null terminated string to be written to file
 *
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t lenwrite;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
/*
 *	if (text_content == NULL)
 *	{
 *		write(fd, "", 0);
 *		lenwrite = 1;
 *	}
 */
	if (text_content != NULL)
		lenwrite = write(fd, text_content, strlen(text_content));

	close(fd);

	if (lenwrite == -1)
		return (-1);

	return (1);
}
