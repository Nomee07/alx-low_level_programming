#include <stdio.h>
#include "function_pointers.h"

/**
 * array_iterator - Executes a function on each element of an array.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * @action: A pointer to the function.
 *
 * Return: void
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

		if (array != NULL || action != NULL)

		{
			for (i = 0; i < size; i++)

			action(array[i]);
		}
}
