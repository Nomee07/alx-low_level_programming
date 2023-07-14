#include <stdio.h>
/**
 * main -Entry point
 * Return: always 0 (Success)
 */
int main(void)
{
int i = 0;
while (i < 10)
{
putchar('0' + i);
putchar('\n');
i++;
}
return (0);
}
