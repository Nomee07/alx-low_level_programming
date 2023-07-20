#include "main.h"
#include <stdio.h>
/**
 * print_to_98 - Print all natural numbers from n to 98
 * @n: The number to start printing from
 * Return: Always 0
 */
void print_to_98(int n)
{
if (n <= 98)
{
for (n = n; n <= 97; n++)
printf("%d, ", n);
}
else
{
for (n = n; n >= 98; n--)
printf("%d, ", n);
}
printf("98\n");
}
