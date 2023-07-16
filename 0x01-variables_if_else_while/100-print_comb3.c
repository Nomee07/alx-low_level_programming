#include <stdio.h>
/**
 * main - Entry point
 * Return: always 0 (Success)
 */
int main(void)
{
int i, j;
for (i = 0; i < 10; i++)
{
for (j = i + 1; j < 10; j++)
{
putchar('0' + i);
putchar('0' + j);
putchar(',');
}
}
putchar('\b');
putchar('\n');
return (0);
}
