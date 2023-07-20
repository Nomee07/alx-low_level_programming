#include <stdio.h>
/**
 * main - prints the first 50 fibonacci, starting with 1 and 2
 * followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)
{
int n = 50;
int fib1 = 1, fib2 = 2;
printf("%d, %d", fib1, fib2);
for (int i = 2; i < n; i++)
{
int next_fib = fib1 + fib2;
printf(", %d", next_fib);
fib1 = fib2;
fib2 = next_fib;
}
printf("\n");
return (0);
}
