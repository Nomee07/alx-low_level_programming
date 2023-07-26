#include "main.h"
#include <limits.h>

/**
 * _atoi - Converts a string to an integer.
 * @s: The input string.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
	int c = 0;
	int sign = 1;
	int result = 0;
	int has_digits = 0;

	while (s[c] == ' ')
	{
	c++;
	}
	while (s[c] == '-' || s[c] == '+')
	{
	sign = (s[c] == '-') ? -sign : sign;
	c++;
	}
	while (s[c] >= '0' && s[c] <= '9')
	{
	has_digits = 1;
	if (result > INT_MAX / 10 ||
	(result == INT_MAX / 10 && s[c] - '0' > INT_MAX % 10))
	{
	return ((sign == 1) ? INT_MAX : INT_MIN);
	}
	result = result * 10 + (s[c] - '0');
	c++;
	}
	if (!has_digits)
	{
	return (0);
	}
	return (result * sign);
}
