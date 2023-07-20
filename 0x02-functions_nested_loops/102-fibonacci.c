#include <stdio.h>
/**
 * main - prints the first 50 fibonacci numbers, starting with 1 and 2
 * followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)
{
long int i, j, k, next;
j = 1;
k = 2;
for (i = 1; i <= 50; ++i)
{
printf("%ld", j);
if (i < 50)
printf(", ");
else
printf("\n");
next = j + k;
j = k;
k = next;
}
return (0);
}
