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
 * copy_file - Copies the content of one file to another file.
 * @src_filename: Source file name.
 * @dest_filename: Destination file name.
 */

void copy_file(const char *src_filename, const char *dest_filename)
{
	int fd_from = open(src_filename, O_RDONLY);
	int fd_to = open(dest_filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	if (fd_from == -1)
	{
		error_exit(98, "Error: Can't read from file %s\n", src_filename);
	}
	if (fd_to == -1)
	{
		error_exit(99, "Error: Can't write to file %s\n", dest_filename);
	}

	while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			error_exit(99, "Error: Can't write to file %s\n", dest_filename);
		}
	}
	if (bytes_read == -1)
	{
		error_exit(98, "Error: Can't read from file %s\n", src_filename);
	}
	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		error_exit(100, "Error: Can't close file descriptors\n");
	}
}

/**
 * main - Entry point for the cp program.
 * @argc: Numer of command-line args.
 * @argv: Array of strings containing the args.
 * Return: 0 on success, other values on failure.
 */

int main(int argc, char *argv[])
{
	const char *src_filename = argv[1];
	const char *dest_filename = argv[2];

	if (argc != 3)
	{
		error_exit(97, "Usage: cp file_from file_to\n");
	}
	if (src_filename[0] == '\0' || dest_filename[0] == '\0')
	{
		error_exit(97, "Usage: cp file_from file_to\n");
	}

	copy_file(src_filename, dest_filename);

	return (0);
}
