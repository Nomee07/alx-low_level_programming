#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 26
/**
 * random_in_range - Generate a random number within the given range.
 * @min: The minimum value.
 * @max: The maximum value.
 *
 * Return: The random number within the range.
 */

int random_in_range(int min, int max);
/**
 * main - Generate a random valid password for the 101-crackme program.
 *
 * Return: Always 0.
 */
int main(void)
{
char password[PASSWORD_LENGTH + 1];
int i, rand_char;

srand(time(0));
for (i = 0; i < PASSWORD_LENGTH; i++)
{
rand_char = random_in_range(1, 3);

if (rand_char == 1)
{
password[i] = random_in_range('a', 'z');
}
else if (rand_char == 2)
{
password[i] = random_in_range('A', 'Z');
}
else
{
password[i] = random_in_range('0', '9');
}
}
password[PASSWORD_LENGTH] = '\0';
printf("%s\n", password);
return (0);
}
/**
 * random_in_range - Generate a random number within the given range.
 * @min: The minimum value.
 * @max: The maximum value.
 *
 * Return: The random number within the range.
 */
int random_in_range(int min, int max)
{
return (rand() % (max - min + 1) + min);
}
