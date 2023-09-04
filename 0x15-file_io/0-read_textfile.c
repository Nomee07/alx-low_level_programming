#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/**
 * read_textfile - Reads a text file and prints to the POSIX std output.
 * @filename: Name of the file to be read.
 * @letters: Number of letters to read and print.
 *
 * Return: The actual number of letters it could read and print
 *	or 0 if failure.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes_read, bytes_written;
	char *buffer;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}
	bytes_read = read(fd, buffer, letters);
	if (bytes_read == -1)
	{
		close(fd);
			free(buffer);
		return (0);
	}
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	close(fd);
	free(buffer);

	if (bytes_written == bytes_read)
		return (bytes_read);

	return (0);
}
