#include "main.h"
#include <stdio.h>

/**
 * _strspn - Gets length of a prefix substring.
 * @s: The string to search in.
 * @accept: String containing the acceptable characters.
 *
 * Return: Always 0 (Success)
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int found = 1;

	while (*s && found)
	{
	found = 0;
	for (char *a = accept; *a; a++)
	{
		if (*s == *a)
	{
		count++;
		found = 1;
		break;
	}
	}
		s++;
	}

	return (count);
}
