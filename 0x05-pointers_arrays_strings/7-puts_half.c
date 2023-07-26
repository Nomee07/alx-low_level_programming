#include "main.h"
#include <stddef.h>

/**
 * puts_half - Prints the second half of a string, followed by a new line
 * @str: The input string
 */
void puts_half(char *str)
{
	int length = 0;
	char *ptr = str;
	int start_index;

	if (str == NULL)
	return;

	while (*ptr != '\0')
	{
	length++;
	ptr++;
	}

	start_index = (length + 1) / 2;

	while (str[start_index] != '\0')
	{
	_putchar(str[start_index]);
	start_index++;
	}

	_putchar('\n');
}
