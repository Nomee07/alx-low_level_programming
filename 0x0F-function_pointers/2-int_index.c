#include <stdio.h>
#include "function_pointers.h"

/**
 * int_index - Returns the index of the first element.
 * @array: Array.
 * @size: number of elements in the array.
 * @cmp: number of elements in the array.
 * Return: Always 0 (Success)
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array != NULL && cmp != NULL && size > 0)
	{

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
			return (i);
	}
	}
	return (-1);
}
