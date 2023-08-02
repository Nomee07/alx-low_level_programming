#include "main.h"
#include <stdio.h>
#include <stdbool.h>

int _strlen(char *s);
int check_palindrome(char *s, int start, int end);

/**
 * is_palindrome - Check if a string is a palindrome
 * @s: Pointer to the input string
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = _strlen(s);

	return (check_palindrome(s, 0, len - 1));
}

/**
 * _strlen - Calculate the length of a string
 * @s: Pointer to the input string
 *
 * Return: Length of the string
 */
int _strlen(char *s)
{
	if (*s == '\0')
	return (0);
	return (1 + _strlen(s + 1));
}

/**
 * check_palindrome - Recursive function to check if a string is palindrome
 * @s: Pointer to the input string
 * @start: Starting index of the substring to check
 * @end: Ending index of the substring to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int check_palindrome(char *s, int start, int end)
{
	if (start >= end)
	return (1);
	if (s[start] != s[end])
	return (0);
	return (check_palindrome(s, start + 1, end - 1));
}
