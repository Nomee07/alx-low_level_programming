#include <stdio.h>
/**
 * main - Entry point
 * Return: always 0 (Success)
 */
int main(void)
{
int i = 0;
putchar('0');
while (i < 9)
{
i++;
putchar(',');
putchar(' ');
putchar(i + '0');
}
putchar('\n');
return (0);
}
