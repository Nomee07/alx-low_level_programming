#include <stddef.h>
#include "main.h"

/**
 * puts2 - Prints character of a string, starting with the first character
 * @str: The input string
 */
void puts2(char *str)
{
	int i;

	if (str == NULL)
	return;

	for (i = 0; str[i] != '\0'; i += 2)
	{
	_putchar(str[i]);
	}
	_putchar('\n');
}
