#include "main.h"

/**
 * test_num_args - Checks to ensure argc is 3
 * @argc: number of arguments passed
 *
 * Return: void
 */
void test_num_args(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * test_file_from - Checks that file_from is valid
 *
 * @check: -1 if fd_from open command failed, positive int otherwise
 * @file: file_from file name
 * @fd_from: file descriptor of file_from
 * @fd_to: file descriptor of file_to
 *
 * Return: void
 */

void test_file_from(ssize_t check, char *file, int fd_from, int fd_to)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		if (fd_from != -1)
			close(fd_from);
		if (fd_to != -1)
			close(fd_to);
		exit(98);
	}
}

/**
 * test_file_to - Checks that file_to was created
 * @check: -1 if fd_to open command failed, positive int otherwise
 * @file: file_to file name
 * @fd_from: file descriptor of file_from
 * @fd_to: file descriptor of file_to
 *
 * Return: void
 */

void test_file_to(ssize_t check, char *file, int fd_from, int fd_to)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		if (fd_from != -1)
			close(fd_from);
		if (fd_to != -1)
			close(fd_to);
		exit(99);
	}
}

/**
 * test_good_close - Test that fd_close worked
 * @close: Return from close
 * @fd: File Descriptor of closed file
 *
 * Return: void
 */

void test_good_close(int close, int fd)
{
	if (close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies content in file_from to file_to
 *
 * @argc: Count of arguments passed
 * @argv: array of pointers to arguments passed
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to, close_from, close_to;
	ssize_t lenread, lenwrite;
	char buf[1024];
	mode_t permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	test_num_args(argc);

	fd_from = open(argv[1], O_RDONLY);
	test_file_from((ssize_t)fd_from, argv[1], -1, -1);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, permissions);
	test_file_to((ssize_t)fd_to, argv[2], fd_from, -1);

	lenread = 1024;

	while (lenread == 1024)
	{
		lenread = read(fd_from, buf, 1024);
		test_file_from(lenread, argv[1], fd_from, fd_to);
		lenwrite = write(fd_to, buf, lenread);
		if (lenwrite != lenread)
			lenwrite = -1;
		test_file_to(lenwrite, argv[2], fd_from, fd_to);
	}

	close_to = close(fd_to);
	close_from = close(fd_from);

	test_good_close(close_to, fd_to);
	test_good_close(close_from, fd_from);
	return (0);
}
