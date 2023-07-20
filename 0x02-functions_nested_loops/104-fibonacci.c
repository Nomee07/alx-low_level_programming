#include <stdio.h>
/**
 * main - prints the first 98 Fibonacci numbers
 * followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)
{
int i;
unsigned long int fib1 = 1, fib2 = 2, next;
printf("%lu, %lu", fib1, fib2);
for (i = 2; i < 98; i++)
{
next = fib1 + fib2;
printf(", %lu", next);
fib1 = fib2;
fib2 = next;
}
printf("\n");
return (0);
}
