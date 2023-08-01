#include "main.h"
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: 0n success 1
 * On error, -1 is returned, and errno is set appropritely.
 */

int _putchar(char c)
{
	return(write(1, &c, 1));
}
