#include "main.h"
#include <stdio.h>

/**
 * _strncat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string to be appended.
 * @n: The maximum number of bytes to be used from src.
 *
 * Return: Pointer to the resulting string dest.
 */

char *_strncat(char *dest, char *src, int n)
{
	char *dest_ptr = dest;

	while (*dest_ptr != '\0')
	dest_ptr++;
	while (*src != '\0' && n > 0)
	{
	*dest_ptr = *src;
	dest_ptr++;
	src++;
	n--;
	}

	*dest_ptr = '\0';

	return (dest);
}
