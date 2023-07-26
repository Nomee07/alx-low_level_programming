#include "main.h"
#include <stdio.h>

/**
 * print_array - Prints n elements of an array integers, followed by a new line
 * @a: The input array of integers
 * @n: The number of elements to print
 */
void print_array(int *a, int n)
{
	int j;

	for (j = 0; j < n; j++)
	{
	printf("%d", a[j]);

	if (j != (n - 1))
	{
	printf(", ");
	}
	}
	printf("\n");
}
