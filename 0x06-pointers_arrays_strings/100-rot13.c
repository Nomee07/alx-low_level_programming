#include "main.h"
#include <stdlib.h>

/**
 * rot13 - Encodes a string using the ROT13 algorithm.
 * @str: The input string to be encoded
 * Return: A pointer to the modified string.
 */

char *rot13(char *str)
{
	char *p;

	if (str == NULL)
		return (NULL);


	for (p = str; *p; p++)

	{
		char c = *p;

		if (c >= 'A' && c <= 'Z')
			*p = ((*p - 'A' + 13) % 26) + 'A';
		else if (c >= 'a' && c <= 'z')
			*p = ((*p - 'a' + 13) % 26) + 'a';

	}

	return (str);
}
