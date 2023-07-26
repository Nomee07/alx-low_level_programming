#include "main.h"
#include <stdio.h>

/**
 * puts2 - Prints character of a string, starting with the first character
 * @str: The input string
 */
void puts2(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i += 2)
	{
	putchar(str[i]);
	}
	putchar('\n');
}
