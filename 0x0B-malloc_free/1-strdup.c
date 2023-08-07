#include <stdlib.h>
#include "main.h"

/**
 * _strdup - Duplicate a string using malloc
 * @str: Input string to be duplicated
 * Return: Pointer to the duplicated string or NULL
 */

char *_strdup(char *str)
{
	unsigned int len = 0, i;
	char *duplicate;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	duplicate = malloc(sizeof(char) * (len + 1));
	if (duplicate == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		duplicate[i] = str[i];

	return (duplicate);
}
