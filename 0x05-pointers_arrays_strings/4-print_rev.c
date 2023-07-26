#include <stdio.h>

/**
 * print_rev - Prints a string in reverse, followed by a new line.
 *
 * @s: Pointer to the string to be printed in reverse.
 */

void print_rev(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
	length++;
	s++;
	}
	s--;
	while (length > 0)
	{
	putchar(*s);
	s--;
	length--;
	}

	putchar('\n');
}
