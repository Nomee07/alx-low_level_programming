#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: Name of the file to append to.
 * @text_content: Text content to append to the file.
 *
 * Return: 1 on success and -1 on failure.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, write_result;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		write_result = write(fd, text_content, strlen(text_content));
		if (write_result == -1)
		{
		close(fd);
		return (-1);
		}
	}
	close(fd);
	return (1);
}
