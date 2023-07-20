#include "main.h"

void positive_or_negative(int i)
{
int n;
srand(time(0));
n = rand() - RAND_MAX / 2;
printf("%d", n);
if (n > 0)
printf("is positive\n");
printf(" is positive\n");
if (n == 0)
printf("is zero\n");
printf(" is zero\n");
if (n < 0)
printf("is negative\n");
printf(" is negative\n");
return (0);
}
