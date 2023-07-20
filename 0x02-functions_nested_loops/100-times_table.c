#include "main.h"
#include <stdio.h>
/**
 * prints_times_table - Prints the n times, starting with 0
 * @n: The number specifying the size of the times table
 * Return: Always 0
 */
void print_times_table(int n)
{
int x, y, z;
if (n < 0 || n > 15)
return;
for (x = 0; x <= n; x++)
{
for (y = 0; y <= n; y++)
{
z = x * y;
if (z > 99)
printf("%d, ", z);
else if (z > 9)
printf("%d, ", z);
else
printf("%d, ", z);
}
printf("\n");
}
}
