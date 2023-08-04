#include <stdio.h>
#include <stdlib.h>

/**
 * get_min_coins - Calculate the minimum number of coins needed for change
 * @cents: The amount of cents to give back
 * Return: The minimum number of coins needed
 */

int get_min_coins(int cents)
{
	int coins[] = {25, 10, 5, 2, 1};
	int num_coins = 0;
	int i;

	if (cents <= 0)
		return (0);

	for (i = 0; i < 5; i++)
	{
		while (cents >= coins[i])
		{
			cents -= coins[i];
			num_coins++;
		}
	}
	return (num_coins);
}

/**
 * main - Entry point of the program
 * @argc: The number of arguments
 * @argv: The array of arguments
 * Return: 0 on success, 1 on error
 */

int main(int argc, char *argv[])
{
	int cents, num_coins;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}
	num_coins = get_min_coins(cents);
	printf("%d\n", num_coins);

	return (0);
}
