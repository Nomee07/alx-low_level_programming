#include "main.h"

/**
 * _strpbrk - Searches a string for any of a set of bytes.
 * @s: The input string to be searched.
 * @accept: The set of bytes to be searched for.
 *
 * Return: Always 0 (Success)
 */
char *_strpbrk(char *s, char *accept)
{
	while (*s)

	{
		char *a = accept;

		while (*a)
	{
		if (*s == *a)
		return (s);
		a++;
	}
		s++;
	}
	return (NULL);
}
