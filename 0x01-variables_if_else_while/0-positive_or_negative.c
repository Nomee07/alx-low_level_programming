#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 *main - Entry point
 *Return: always 0 (Success)
*/
int main(void)
{
int n;
srand(time(0));
n = rand() - RAND_MAX / 2;
printf("%d", n);
if (n > 0)
printf(" is positive\n");
if (n == 0)
printf(" is zero\n");
if (n < 0)
printf(" is negative\n");
return (0);
}