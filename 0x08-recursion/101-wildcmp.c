#include "main.h"
#include <stdio.h>

/**
 * wildcmp - Compare two strings considering wildcard character '*'
 * @s1: Pointer to the first string
 * @s2: Pointer to the second string
 *
 * Return: 1 if strings identical, otherwise 0
 */

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));

		if (wildcmp(s1, s2 + 1))
			return (1);
		return (wildcmp(s1 + 1, s2));
	}
	return (0);
}
