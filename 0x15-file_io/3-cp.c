#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
/**
 * error_exit - Prints an error message and exit with the given code.
 * @code: Exit code.
 * @format: Format string for the error message.
 * @...: Args for the format string.
 */

void error_exit(int code, const char *format, ...)
{
	va_list args;

	va_start(args, format);
	dprintf(STDERR_FILENO, format, args);
	va_end(args);
	exit(code);
}

/**
 * main - Entry point for the cp program.
 * @argc: Numer of command-line args.
 * @argv: Array of strings containing the args.
 *
 * Return: 0 on success, other values on failure.
 */

int main(int argc, char *argv[])
{
	int fd_from = open(argv[1], O_RDONLY);
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;
	int fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (argc != 3)
	{
		error_exit(97, "Usage: cp file_from file_to\n");
	}

	if (fd_from == -1)
	{
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);
	}
	if (fd_to == -1)
	{
		error_exit(99, "Error: Can't write to file %s\n", argv[2]);
	}
	while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		ssize_t bytes_written = write(fd_to, buffer, bytes_read);

		if (bytes_written == -1)
		{
			error_exit(99, "Error: Can't write to file %s\n", argv[2]);
		}
	}
	if (bytes_read == -1)
	{
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);
	}
	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		error_exit(100, "Error: Can't close fd\n");
	}
	return (0);
}
