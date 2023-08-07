#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenate two strings using
 * @s1: The first input string
 * @s2: The second input string
 * Return: Pointer to the concatenated string or NULL
 */

char *str_concat(char *s1, char *s2)
{
	unsigned int len1 = 0, len2 = 0, i, j;
	char *concatenated;

	if (s1 != NULL)
	{
		while (s1[len1])
			len1++;
	}

	if (s2 != NULL)
	{
		while (s2[len2])
			len2++;
	}

	concatenated = malloc(sizeof(char) * (len1 + len2 + 1));
	if (concatenated == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		concatenated[i] = s1[i];
	for (j = 0; j < len2; j++)
		concatenated[i + j] = s2[j];

	concatenated[i + j] = '\0';
	return (concatenated);
}
