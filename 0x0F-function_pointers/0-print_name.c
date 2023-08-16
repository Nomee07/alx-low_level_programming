#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - A function that prints a name.
 * @name: A pointer to the name string.
 * @f: A pointer to a function.
 *
 * Return: Always 0
 */

void print_name(char *name, void (*f)(char *))
{
	if (name != NULL || f != NULL)
		f(name);
}
