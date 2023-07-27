#include "main.h"
#include <stdio.h>

/**
 * leet - Encodes a string into 1337 (leet speak).
 * @str: The input string to encode.
 *
 * Return: A pointer to the encoded string.
 */

char *leet(char *str)
{
	char *leet_chars = "aAeEoOtTlL";
	char *leet_replacements = "4433007711";
	int i, j;

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; leet_chars[j] != '\0'; j++)
		{
			if (str[i] == leet_chars[j])
			{
				str[i] = leet_replacements[j];
				break;
			}
		}
	}
	return (str);
}
