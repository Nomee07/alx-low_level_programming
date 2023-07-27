#include "main.h"
#include <stdio.h>

/**
 * cap_string - Capitalizes all words of a string.
 * @str: The input string.
 *
 * Return: Pointer to the resulting string.
 */

char *cap_string(char *str)
{
	char *ptr = str;
	int in_word = 0;

	while (*ptr != '\0')
	{
	if (*ptr >= 'a' && *ptr <= 'z')
	{

	if (!in_word)
	*ptr -= ('a' - 'A');

	in_word = 1;
	}
	else
	{

	if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' ||
	*ptr == ',' || *ptr == ';' || *ptr == '.' ||
	*ptr == '!' || *ptr == '?' || *ptr == '"' ||
	*ptr == '(' || *ptr == ')' || *ptr == '{' ||
	*ptr == '}')
	{
	in_word = 0;
	}
	}
	ptr++;
	}

	return (str);
}
